#ifndef AVLTREE_H
# define AVLTREE_H

#include "node.h"

class AVLTree
{
public:
	AVLTree(Node *node = nullptr);

	void insert(int value);
	Node *find(int value, Node *node);
    Node *del(int value, Node *node);
private:
	Node *root;

	int height(Node *node);
	void left_rotation(Node *node);
	void right_rotation(Node *node);
	int check_balance(Node *node);
};

#endif