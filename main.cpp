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

int main() {
	const std::string str = "I AM SAM. I AM SAM. SAM I AM.\nTHAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!";

	Encoder encoder(str);
	encoder.Encode();

	for (auto& x: encoder.compressed) {
			std::cout << std::bitset<16>(x);
	}

	std::cout << '\n';


	return 0;
}
