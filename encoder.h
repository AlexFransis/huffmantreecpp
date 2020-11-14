#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <memory>
#include "huffmantree.h"

class Encoder {
	private:
		void createFrequencyTable();
		void createMinQueue();
		void createHuffmanTree();
		void createHuffmanCodes();
		void createEncodedStream();

	public:
		char const* byteArr;
		std::unordered_map<char, int> freqTable;
		std::priority_queue<HuffmanTreeNode, std::vector<std::shared_ptr<HuffmanTreeNode>>, NodeComparison> pq;
		std::unordered_map<char, std::vector<int>> huffmanCodes;

		Encoder(const std::string&);

		void encode();
};

