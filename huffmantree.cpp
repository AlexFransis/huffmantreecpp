#include "huffmantree.h"
#include <memory>

// ********************************
// HuffmanTreeNode implementation
// ********************************
HuffmanTreeNode::HuffmanTreeNode(char c, int freq) {
	character = c;
	frequency = freq;
	left = nullptr;
	right = nullptr;
}

void HuffmanTreeNode::setLeft(std::shared_ptr<HuffmanTreeNode> node) {
	left = node;
}

void HuffmanTreeNode::setRight(std::shared_ptr<HuffmanTreeNode> node) {
	right = node;
}

std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::getLeft() {
	return left;
}

std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::getRight() {
	return right;
}

// ********************************
// NodeComparison implementation
// ********************************
bool NodeComparison::operator()(const std::shared_ptr<const HuffmanTreeNode> node1, 
								const std::shared_ptr<const HuffmanTreeNode> node2) {
	return node1->frequency > node2->frequency;
}
