#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <memory>
#include <iostream>
#include <bitset>
#include "huffmantree.h"

class Encoder {
	private:
		char const* byte_arr;

		void CreateFrequencyTable();
		void CreateMinQueue();
		void CreateHuffmanTree();
		void CreateHuffmanCodes();
		void CreateEncodedStream();
		void CompressEncodedStream();
		int GetTotalCompressedSize();

	public:
		std::vector<uint8_t> compressed;
		std::vector<uint8_t> encoded_stream;
		std::unordered_map<char, int> freq_table;
		std::priority_queue<HuffmanTreeNode, std::vector<std::shared_ptr<HuffmanTreeNode>>, NodeComparison> pq;
		std::unordered_map<char, std::vector<uint8_t>> huffman_codes;

		Encoder(const std::string&);

		void Encode();
		std::string Decode();
};
