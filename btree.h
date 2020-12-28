#ifndef BTREE_H
# define BTREE_H

# include "node.h"

class BTree
{
public:
	Node *root;
	
	BTree();
	BTree(Node *node);

	void insert(int value, Node *node);
	void remove(int value);

	Node* search_parent(int value, Node* node);
	Node* search(int value, Node* node);
	Node* min(Node *root);
	Node* max(Node *root);

	// обход дерева
	void walk_preffix(Node *node);
	void walk_infix(Node *node);
	void walk_suffix(Node *node);
};

#endif