#include <memory>

class HuffmanTreeNode {
	private:
		std::unique_ptr<HuffmanTreeNode> left;
		std::unique_ptr<HuffmanTreeNode> right;

	public:
		char character;
		int frequency;

		HuffmanTreeNode(char, int);

		void setLeft(const std::unique_ptr<HuffmanTreeNode>&);
		void setRight(const std::unique_ptr<HuffmanTreeNode>&);
		const std::unique_ptr<HuffmanTreeNode> getLeft() const;
		const std::unique_ptr<HuffmanTreeNode> getRight() const;
};

class NodeComparison {
	public:
		bool operator() (const std::unique_ptr<HuffmanTreeNode>&, const std::unique_ptr<HuffmanTreeNode>&);
};
