#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include "encoder.h"

using namespace std;

Encoder::Encoder(const string& s) {
	str = s;
}

void Encoder::createFrequencyTable() {
	unordered_map<char, int> umap;
	for (int i = 0; i < str.length(); i++) {
		char c = str[i];
		auto got = umap.find(c);
		int frequency = 1;
		if (got == umap.end()) {
			umap.insert(make_pair(c, frequency));
			continue;
		}
		// increment frequency
		(got->second)++;
	}

	freqTable = umap;
}

void Encoder::createMinQueue() {
	typedef priority_queue<HuffmanTreeNode, vector<shared_ptr<HuffmanTreeNode>>, NodeComparison> min_heap;
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
