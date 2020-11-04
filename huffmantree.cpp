#include "huffmantree.h"
#include <memory>

// HuffmanTreeNode implementation
//

HuffmanTreeNode::HuffmanTreeNode(char c, int freq) {
	character = c;
	frequency = freq;
	left = nullptr;
	right = nullptr;
}

int HuffmanTreeNode::getValue() {
	if (left == nullptr && right == nullptr) {
		return frequency;
	}

	return left->getValue() + right->getValue();
}

void HuffmanTreeNode::addLeft(char c, int freq) {
	auto node = std::make_shared<HuffmanTreeNode>(c, freq);
	left = node;
}

void HuffmanTreeNode::addRight(char c, int freq) {
	auto node = std::make_shared<HuffmanTreeNode>(c, freq);
	right = node;
}

std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::getLeft() {
	return left;
}

std::shared_ptr<HuffmanTreeNode> HuffmanTreeNode::getRight() {
	return right;
}

// NodeComparison implementation
bool NodeComparison::operator()(const HuffmanTreeNode& node1, const HuffmanTreeNode& node2) {
	return node1.frequency > node2.frequency;
}

// HuffmanTree implementation

void HuffmanTree::setRoot(HuffmanTreeNode& node) {
	root = &node;
}

HuffmanTreeNode* HuffmanTree::getRoot() {
	return root;
}
