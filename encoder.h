#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include "huffmantree.h"

using namespace std;

class Encoder {
	public:
		string str;
		unordered_map<char, int> freqTable;
		priority_queue<HuffmanTreeNode, vector<HuffmanTreeNode>, NodeComparison> pq;

		Encoder(const string&);

		void createFrequencyTable();
		void createMinQueue();
		void createHuffmanTree();
};

