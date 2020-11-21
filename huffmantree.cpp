#include "huffmantree.h"

// ********************************
// HuffmanTreeNode implementation
// ********************************
HuffmanTreeNode::HuffmanTreeNode(char c, int freq) {
	character = c;
	frequency = freq;
	left = nullptr;
	right = nullptr;
}

void HuffmanTreeNode::setLeft(const std::shared_ptr<HuffmanTreeNode>& node) {
	left = node;
}

void HuffmanTreeNode::setRight(const std::shared_ptr<HuffmanTreeNode>& node) {
	right = node;
}

const std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::GetLeft() const {
	return left;
}

const std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::GetRight() const {
	return right;
}

const std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::GetChild(bool direction) const {
	// (0) -> left | (1) -> right
	if (direction) {
		return GetRight();
	}
	return GetLeft();
}

// ********************************
// NodeComparison implementation
// ********************************
bool NodeComparison::operator()(const std::shared_ptr<HuffmanTreeNode>& node1,
								const std::shared_ptr<HuffmanTreeNode>& node2) {
	return node1->frequency > node2->frequency;
}
