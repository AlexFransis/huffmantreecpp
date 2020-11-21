#include <memory>

class HuffmanTreeNode {
	private:
		std::shared_ptr<HuffmanTreeNode> left;
		std::shared_ptr<HuffmanTreeNode> right;

	public:
		char character;
		int frequency;

		HuffmanTreeNode(char, int);


		void setLeft(const std::shared_ptr<HuffmanTreeNode>&);
		void setRight(const std::shared_ptr<HuffmanTreeNode>&);
		const std::shared_ptr<HuffmanTreeNode> GetLeft() const;
		const std::shared_ptr<HuffmanTreeNode> GetRight() const;
		const std::shared_ptr<HuffmanTreeNode> GetChild(bool) const;
};

class NodeComparison {
	public:
		bool operator() (const std::shared_ptr<HuffmanTreeNode>&, const std::shared_ptr<HuffmanTreeNode>&);
};
