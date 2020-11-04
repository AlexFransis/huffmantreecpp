#include <memory>

class HuffmanTreeNode {
	private:
		std::shared_ptr<HuffmanTreeNode> left;
		std::shared_ptr<HuffmanTreeNode> right;

	public:
		char character;
		int frequency;

		HuffmanTreeNode(char, int);

		int getValue();
		void addLeft(char, int);
		void addRight(char, int);
		std::shared_ptr<HuffmanTreeNode> getLeft();
		std::shared_ptr<HuffmanTreeNode> getRight();
};

class NodeComparison {
	public:
		bool operator() (const HuffmanTreeNode&, const HuffmanTreeNode&);
};

class HuffmanTree {
	private:
		HuffmanTreeNode* root;

	public:
		void setRoot(HuffmanTreeNode&);
		HuffmanTreeNode* getRoot();
};
