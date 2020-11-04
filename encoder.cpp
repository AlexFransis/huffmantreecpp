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
		(got->second)++;
	}

	freqTable = umap;
}

void Encoder::createMinQueue() {
	typedef priority_queue<HuffmanTreeNode, vector<HuffmanTreeNode>, NodeComparison> min_heap;
	min_heap minHeap;

	// add frequency table elements to min queue
	for (auto x : freqTable) {
		HuffmanTreeNode node(x.first, x.second);
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
		//HuffmanTreeNode node;
		//node.addLeft;
	}
}
