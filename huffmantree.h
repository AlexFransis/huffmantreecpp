#include <memory>

class HuffmanTreeNode {
	private:
		std::shared_ptr<HuffmanTreeNode> left;
		std::shared_ptr<HuffmanTreeNode> right;

	public:
		char character;
		int frequency;

		HuffmanTreeNode(char, int);

		void setLeft(std::shared_ptr<HuffmanTreeNode>);
		void setRight(std::shared_ptr<HuffmanTreeNode>);
		std::shared_ptr<HuffmanTreeNode> getLeft();
		std::shared_ptr<HuffmanTreeNode> getRight();
};

class NodeComparison {
	public:
		bool operator() (const std::shared_ptr<const HuffmanTreeNode>, const std::shared_ptr<const HuffmanTreeNode>);
};
