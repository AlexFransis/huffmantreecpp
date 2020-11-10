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

void HuffmanTreeNode::setLeft(const std::unique_ptr<const HuffmanTreeNode>& node) {
	left = node;
}

void HuffmanTreeNode::setRight(const std::unique_ptr<const HuffmanTreeNode>& node) {
	right = node;
}

const std::unique_ptr<const HuffmanTreeNode> HuffmanTreeNode::getLeft() const {
	return left;
}

const std::unique_ptr<const HuffmanTreeNode> HuffmanTreeNode::getRight() const {
	return right;
}

// ********************************
// NodeComparison implementation
// ********************************
bool NodeComparison::operator()(const std::unique_ptr<const HuffmanTreeNode>& node1,
								const std::unique_ptr<const HuffmanTreeNode>& node2) {
	return node1->frequency > node2->frequency;
}
