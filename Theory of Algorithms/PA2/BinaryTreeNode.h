#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

class BinaryTreeNode {

public:

	char character;
	int value;
	BinaryTreeNode *left, *right;

	BinaryTreeNode(char c, int val) {
		this->character = c;
		value = val;
		left = nullptr;
		right = nullptr;
	}
};

#endif /* BINARYTREENODE_H_ */
