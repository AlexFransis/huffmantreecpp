#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <memory>
#include "huffmantree.h"

using namespace std;

class Encoder {
	private:
		void createFrequencyTable();
		void createMinQueue();
		void createHuffmanTree();

	public:
		string str;
		unordered_map<char, int> freqTable;
		priority_queue<std::unique_ptr<HuffmanTreeNode>, vector<std::unique_ptr<HuffmanTreeNode>>, NodeComparison> pq;

		Encoder(const string&);

		void encode();

};

