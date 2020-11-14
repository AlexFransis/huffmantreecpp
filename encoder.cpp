#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <math.h>
#include "encoder.h"

// Helper function to create huffman codes
void traverseHuffmanTree(const std::shared_ptr<const HuffmanTreeNode>& node,
						std::vector<int>& accumulator,
						std::unordered_map<char, std::vector<int>>& umap) {
	if (node->getLeft() == nullptr && node->getRight() == nullptr) {
		std::vector<int> code(accumulator.begin(), accumulator.end());
		umap.insert(std::make_pair(node->character, code));
		accumulator.pop_back();
		return;
	}

	accumulator.push_back(0);
	traverseHuffmanTree(node->getLeft(), accumulator, umap);

	accumulator.push_back(1);
	traverseHuffmanTree(node->getRight(), accumulator, umap);
	accumulator.pop_back();
}

Encoder::Encoder(const std::string& s) {
	const char* buffer = s.c_str();
	byteArr = buffer;
}

void Encoder::createFrequencyTable() {
	std::unordered_map<char, int> umap;
	for (int i = 0; *(byteArr + i) != '\0'; i++) {
		unsigned char c = *(byteArr + i);
		auto got = umap.find(c);
		int frequency = 1;
		if (got == umap.end()) {
			umap.insert(std::make_pair(c, frequency));
			continue;
		}
		// increment frequency
		(got->second)++;
	}

	freqTable = umap;
}

void Encoder::createMinQueue() {
	typedef std::priority_queue<HuffmanTreeNode, std::vector<std::shared_ptr<HuffmanTreeNode>>, NodeComparison> min_heap;
	min_heap minHeap;

	// add frequency table elements to min queue
	for (auto x : freqTable) {
		auto node = std::make_shared<HuffmanTreeNode>(x.first, x.second);
		minHeap.push(node);
	}

	pq = minHeap;
}

void Encoder::createHuffmanTree() {
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

void Encoder::createHuffmanCodes() {
	auto root = pq.top();
	std::vector<int> acc;
	std::unordered_map<char, std::vector<int>> umap;
	traverseHuffmanTree(root, acc, umap);
	huffmanCodes = umap;
}

void Encoder::createEncodedStream() {
	std::vector<int> stream;
	for (int i = 0; *(byteArr + i) != '\0'; i++) {
		char key = *(byteArr + i);
		auto got = huffmanCodes.find(key);
		if (got != huffmanCodes.end()) {
			for (auto it = got->second.begin(); it != got->second.end(); it++) {
				stream.push_back(*it);
			}
		}
	}

	encodedStream = stream;
}

int Encoder::getTotalCompressedSize() {
	int totalBitSize = 0;
	for (auto& x: freqTable) {
		char key = x.first;
		int frequency = x.second;
		auto got = huffmanCodes.find(key);
		if (got != huffmanCodes.end()) {
			int codeLength = got->second.size();
			totalBitSize += codeLength * frequency;
		}
	}

	float bytes = totalBitSize / 8.0;

	return int(ceil(bytes));
}

void Encoder::compressEncodedStream() {
	const int bufferSize = getTotalCompressedSize();
	std::vector<unsigned char> buffer(bufferSize);
	unsigned char byte = 0x00;
	for (int i = 0; i < encodedStream.size(); i++) {
		int bit = encodedStream[i];
		byte = (byte << 1) | bit;
		if ((i + 1) % 8 == 0) {
			buffer.push_back(byte);
			byte = 0x00;
		}
	}

	buffer.push_back(byte);
	compressed = buffer;
}

void Encoder::encode() {
	createFrequencyTable();
	createMinQueue();
	createHuffmanTree();
	createHuffmanCodes();
	createEncodedStream();
	compressEncodedStream();
}

