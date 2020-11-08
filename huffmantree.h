#include <memory>

class HuffmanTreeNode {
	private:
		std::shared_ptr<const HuffmanTreeNode> left;
		std::shared_ptr<const HuffmanTreeNode> right;

	public:
		char character;
		int frequency;

		HuffmanTreeNode(char, int);

		void setLeft(const std::shared_ptr<const HuffmanTreeNode>&);
		void setRight(const std::shared_ptr<const HuffmanTreeNode>&);
		const std::shared_ptr<const HuffmanTreeNode> getLeft() const;
		const std::shared_ptr<const HuffmanTreeNode> getRight() const;
};

class NodeComparison {
	public:
		bool operator() (const std::shared_ptr<const HuffmanTreeNode>&, const std::shared_ptr<const HuffmanTreeNode>&);
};
