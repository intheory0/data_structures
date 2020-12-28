#include "node.h"
#include "btree.h"

#include <iostream>

BTree::BTree()
{
	root = nullptr;
}

BTree::BTree(Node *node)
{
	root = node;
}

void BTree::insert(int value, Node *node)
{
	if (!node)
	{
		Node *a = new Node(value);
		root = a;
		return;
	}
	if (value > node->value)
	{
		if (node->right == nullptr)
		{
			Node *a = new Node(value);
			node->right = a;
		}
		else
		{
			insert(value, node->right);
		}
	}
	else if (value < node->value)
	{
		if (node->left == nullptr)
		{
			Node *a = new Node(value);
			node->left = a;
		}
		else
		{
			insert(value, node->left);
		}
	}
}

void BTree::remove(int value)
{
	Node* found = search(value, root);
	Node* place = nullptr;
	Node* parent = nullptr;

	if (!found)
		return;

	if (found->right != nullptr)
		place = min(found->right);
	else if (found->left != nullptr)
		place = max(found->left);

	if (!place)
		place = found;
	parent = search_parent(place->value, root);
	
	if (parent)
	{
		found->value = place->value;
		
		if (parent->left &&
			parent->left->value == place->value)
			parent->left = nullptr;
		else if(parent->right &&
			parent->right->value == place->value)
			parent->right = nullptr;
	}

	delete place;
}

Node* BTree::search_parent(int value, Node* node)
{
	if (!node)
		return node;
	else if (node->value > value)
	{
		if (!node->left || node->left->value == value)
			return node;
		return search(value, node->left);
	}
	else
	{ 
		if (!node->right || node->right->value == value)
			return node;
		return search(value, node->right);
	}
}

Node* BTree::search(int value, Node* node)
{
	if (!node || node->value == value)
		return node;
	else if (node->value > value)
		return search(value, node->left);
	else
		return search(value, node->right);
}

Node* BTree::min(Node *root)
{
	if(!root || root->left == nullptr)
		return root;
	return min(root->left);
}

Node* BTree::max(Node *root)
{
	if(!root || root->right == nullptr)
		return root;
	return max(root->right);
}

	// обход дерева
void BTree::walk_preffix(Node *node)
{
	if (node == nullptr)
		return;
	std::cout << node->value << " ";
	walk_preffix(node->left);
	walk_preffix(node->right);
}
	
void BTree::walk_infix(Node *node)
{
	if (node == nullptr)
		return;
	walk_infix(node->left);
	std::cout << node->value << " ";
	walk_infix(node->right);
}
	
void BTree::walk_suffix(Node *node)
{
	if (node == nullptr)
		return;
	walk_suffix(node->left);
	walk_suffix(node->right);
	std::cout << node->value << " ";
}