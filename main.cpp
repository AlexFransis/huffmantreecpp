#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "encoder.h"

using namespace std;

void printTree(std::shared_ptr<HuffmanTreeNode> node) {
	if (node != nullptr) {
		cout << "KEY: " << node->character << " VALUE: " << node->frequency << "\n";
		printTree(node->getLeft());
		printTree(node->getRight());
	}
}

int main() {
	const string str = "I AM SAM. I AM SAM. SAM I AM.\nTHAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!";

	Encoder encoder (str);
	encoder.createFrequencyTable();
	encoder.createMinQueue();
	encoder.createHuffmanTree();


	cout << "SIZE: " << encoder.pq.size() << '\n';
	auto x = encoder.pq.top();
	printTree(x);
	/*
	while(!encoder.pq.empty()) {
		auto x = encoder.pq.top();
		cout << "KEY: " << x->character << " VALUE: " << x->frequency << "\n";
		encoder.pq.pop();
	}
	*/

	return 0;
}
