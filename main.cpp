#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <bitset>
#include "encoder.h"

void PrintTree(const std::shared_ptr<const HuffmanTreeNode>& node) {
	if (node != nullptr) {
		std::cout << "KEY: " << node->character << " VALUE: " << node->frequency << "\n";
		PrintTree(node->GetLeft());
		PrintTree(node->GetRight());
	}
}

void PrintCodes(const std::unordered_map<char, std::vector<uint8_t>>& umap) { 
	std::cout << "#### HUFFMAN CODES ####" << '\n';
	for (auto& x : umap) {
		std::cout << "KEY: " << x.first << " CODES: ";
		for (auto& b : x.second) {
			std::cout << (int)b;
		}
		std::cout << '\n';
	}
}

void PrintEncodedStream(const std::vector<uint8_t>& stream) {
	std::cout << "#### ENCODED STREAM ####" << '\n';
	for (auto& x : stream) {
		std::cout << (int)x;
	}
	std::cout << '\n';
}

void PrintCompressed(const std::vector<uint8_t>& compressed) {
	std::cout << "#### COMPRESSED STREAM ####" << '\n';
	for (auto& x : compressed) {
		std::cout << std::bitset<0x08>(x);
	}
	std::cout << '\n';
}

int main() {
	const std::string str = "I AM SAM. I AM SAM. SAM I AM.\nTHAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!";

	Encoder encoder(str);
	encoder.Encode();

	//PrintTree(encoder.pq.top());
	//PrintCodes(encoder.huffman_codes);
	//std::cout << str << '\n';
	PrintEncodedStream(encoder.encoded_stream);
	PrintCompressed(encoder.compressed);

	std::cout << '\n';


	return 0;
}
