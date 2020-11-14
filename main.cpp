#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include "encoder.h"

void printTree(const std::shared_ptr<const HuffmanTreeNode>& node) {
	if (node != nullptr) {
		std::cout << "KEY: " << node->character << " VALUE: " << node->frequency << "\n";
		printTree(node->getLeft());
		printTree(node->getRight());
	}
}

int main() {
	const std::string str = "I AM SAM. I AM SAM. SAM I AM.\nTHAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!";

	Encoder encoder(str);
	encoder.encode();

	/*
	for (auto& x: encoder.huffmanCodes) {
		std::cout << "KEY: " << std::hex << x.first << " CODE: ";
		for (auto iterator = x.second.begin(); iterator != x.second.end(); iterator++) {
			std::cout << *iterator;
		}
		std::cout << "\n";
	}
	*/

	for (auto& x: encoder.encodedStream) {
			std::cout << x;
	}
	std::cout << '\n';

	return 0;
}
