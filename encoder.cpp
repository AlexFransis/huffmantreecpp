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
	typedef priority_queue<std::unique_ptr<HuffmanTreeNode>, vector<unique_ptr<HuffmanTreeNode>>, NodeComparison> min_heap;
	min_heap minHeap;

	// add frequency table elements to min queue
	for (auto x : freqTable) {
		minHeap.push(std::make_unique<HuffmanTreeNode>(x.first, x.second));
	}

	pq = minHeap;
}

void Encoder::createHuffmanTree() {
	while (pq.size() != 1) {
		const auto& min1 = pq.top();
		pq.pop();
		const auto& min2 = pq.top();
		pq.pop();

		auto internalNode = std::make_unique<HuffmanTreeNode>('\0', min1->frequency + min2->frequency);

		internalNode->setLeft(std::move(min1));
		internalNode->setRight(std::move(min2));

		pq.push(internalNode);
	}
}

void Encoder::encode() {
	createFrequencyTable();
	createMinQueue();
	createHuffmanTree();
}
