#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <math.h>
#include "encoder.h"

// Helper function to create huffman codes
void TraverseHuffmanTree(const std::shared_ptr<const HuffmanTreeNode>& node,
						std::vector<uint8_t>& accumulator,
						std::unordered_map<char, std::vector<uint8_t>>& umap) {
	if (node->GetLeft() == nullptr && node->GetRight() == nullptr) {
		std::vector<uint8_t> code(accumulator.begin(), accumulator.end());
		umap.insert(std::make_pair(node->character, code));
		accumulator.pop_back();
		return;
	}

	accumulator.push_back(0);
	TraverseHuffmanTree(node->GetLeft(), accumulator, umap);

	accumulator.push_back(1);
	TraverseHuffmanTree(node->GetRight(), accumulator, umap);
	accumulator.pop_back();
}

Encoder::Encoder(const std::string& s) {
	const char* buffer = s.c_str();
	byte_arr = buffer;
}

void Encoder::CreateFrequencyTable() {
	std::unordered_map<char, int> umap;
	for (int i = 0; *(byte_arr + i) != '\0'; i++) {
		unsigned char c = *(byte_arr + i);
		auto got = umap.find(c);
		int frequency = 1;
		if (got == umap.end()) {
			umap.insert(std::make_pair(c, frequency));
			continue;
		}
		// increment frequency
		(got->second)++;
	}

	freq_table = umap;
}

void Encoder::CreateMinQueue() {
	typedef std::priority_queue<HuffmanTreeNode, std::vector<std::shared_ptr<HuffmanTreeNode>>, NodeComparison> min_heap;
	min_heap minHeap;

	// add frequency table elements to min queue
	for (auto x : freq_table) {
		auto node = std::make_shared<HuffmanTreeNode>(x.first, x.second);
		minHeap.push(node);
	}

	pq = minHeap;
}

void Encoder::CreateHuffmanTree() {
	while (pq.size() != 1) {
		auto min1 = pq.top();
		pq.pop();
		auto min2 = pq.top();
		pq.pop();

		auto internalNode = std::make_shared<HuffmanTreeNode>('\0', min1->frequency + min2->frequency);

		internalNode->setLeft(min1);
		internalNode->setRight(min2);

		pq.push(internalNode);
	}
}

void Encoder::CreateHuffmanCodes() {
	auto root = pq.top();
	std::vector<uint8_t> acc;
	std::unordered_map<char, std::vector<uint8_t>> umap;
	TraverseHuffmanTree(root, acc, umap);
	huffman_codes = umap;
}

void Encoder::CreateEncodedStream() {
	std::vector<uint8_t> stream;
	for (int i = 0; *(byte_arr + i) != '\0'; i++) {
		char key = *(byte_arr + i);
		auto got = huffman_codes.find(key);
		if (got != huffman_codes.end()) {
			for (auto it = got->second.begin(); it != got->second.end(); it++) {
				stream.push_back(*it);
			}
		}
	}

	encoded_stream = stream;
}

int Encoder::GetTotalCompressedSize() {
	int totalBitSize = 0;
	for (auto& x: freq_table) {
		char key = x.first;
		int frequency = x.second;
		auto got = huffman_codes.find(key);
		if (got != huffman_codes.end()) {
			int codeLength = got->second.size();
			totalBitSize += codeLength * frequency;
		}
	}

	float bytes = totalBitSize / 8.0;

	return int(ceil(bytes));
}

void Encoder::CompressEncodedStream() {
	const int compressed_size = GetTotalCompressedSize(); // bytes
	std::vector<uint8_t> buffer;
	uint8_t byte = 0x00;
	int i = 0;
	for (; i < encoded_stream.size(); i++) {
		bool bit = encoded_stream[i];
		byte = (byte << 1) | bit;
		if ((i + 1) % 8 == 0) {
			buffer.push_back(byte);
			byte = 0x00;
		}
	}
	// shift last byte to make sure it is not prepended with 0s
	byte = byte << (compressed_size * 8 - i);
	buffer.push_back(byte);
	compressed = buffer;
}

void Encoder::Encode() {
	CreateFrequencyTable();
	CreateMinQueue();
	CreateHuffmanTree();
	CreateHuffmanCodes();
	CreateEncodedStream();
	CompressEncodedStream();
	std::cout << "#### ENCODING COMPLETE ####\n";
}

std::string Encoder::Decode() {
	std::vector<char> character_buffer;
	auto root = pq.top();
	std::shared_ptr<HuffmanTreeNode>* current_node = &root;
	for (auto& byte: compressed) {
		std::bitset<0x08> bits(byte);
		for (auto& b: bits.to_string()) {
			bool bit = false;
			if (b == '1') {
				bit = true;
			}
			auto child = (*current_node)->GetChild(bit);
			// internal node, continue traversing tree
			if (child->character == '\0') {
				current_node = &child;
				continue;
			}
			// leaf node, get character
			character_buffer.push_back(child->character);
			current_node = &root;
		}
	}

	return std::string(character_buffer.begin(), character_buffer.end());
}
