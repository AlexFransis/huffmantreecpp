#include <iostream>
#include <string>
#include <vector>
#include "encoder.h"

using namespace std;

int main() {
	const string str = "I AM SAM. I AM SAM. SAM I AM.\nTHAT SAM-I-AM! THAT SAM-I-AM! I DO NOT LIKE THAT SAM-I-AM!";

	Encoder encoder (str);
	encoder.createFrequencyTable();
	encoder.createMinQueue();

	HuffmanTreeNode node('o', 0);
	node.addLeft('a', 1);
	node.addRight('b', 2);
	cout << "LEFT KEY: " << node.getLeft()->character << '\n';
	cout << "LEFT VALUE: " << node.getLeft()->getValue() << '\n';
	cout << "RIGHT KEY: " << node.getRight()->character << '\n';
	cout << "RIGHT VALUE: " << node.getRight()->getValue() << '\n';

	cout << "SIZE: " << encoder.pq.size() << '\n';
	while(!encoder.pq.empty()) {
		auto x = encoder.pq.top();
		cout << "KEY: " << x.character << " VALUE: " << x.frequency << "\n";
		encoder.pq.pop();
	}

	return 0;
}
