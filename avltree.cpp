#include <algorithm>
#include "node.h"
#include "avltree.h"

AVLTree::AVLTree(Node *node)
{
	root = node;
}

int AVLTree::height(Node *node)
{
	return (node) ? node->height : 0;
}

int AVLTree::check_balance(Node *node)
{
	return (node) ? height(node->left) - height(node->right) : 0;
}

void AVLTree::left_rotation(Node *node)
{
	Node *right = node->right;
	Node *r_left = right->left;

	right->left = node;
	node->right = r_left;
	
	node->height = std::max(height(node->left), height(node->right)) + 1;
	right->height = std::max(height(right->left), height(right->right)) + 1;
}

void AVLTree::right_rotation(Node *node)
{}

void AVLTree::insert(int value)
{}

Node *AVLTree::find(int value, Node *node)
{
    if (node == nullptr || node->value == value)
        return node;
    else if (node->value > value)
        return find(value, node->left);
    else if (node->value < value)
        return find(value, node->right);
}
/*
Node *AVLTree::del(int value, Node *node)
{
	Node *temp = nullptr;

    //поиск и удаление
    if (!node)
		return nullptr;
	else if (node->value > value)
		node->left = del(value, node->left);
	else if (node->value < value)
		node->right = del(value, node->right);
	else if (node->left && node->right)
	{
		// min(); // in node->right
		// node->value = min->value
		// temp = del(node->value, node->right)
	}
	else
	{
		temp = node;
		if (node->left)
			node = node->left;
		else if (node->right)
			node = node->right;
		delete temp;
	}
    if (!temp)
		return nullptr;

    //балансировка
    if (check_balance(node) == 2)
        if (check_balance(node->left) == 1)
            right_rotation(node);
        else
        {
            left_rotation();
            right_rotation();
        }
    else if (check_balance(node) == -2)
        if (check_balance(node->right) == 1)
        {
            right_rotation();
            left_rotation();
        }
        else
            left_rotation(node);
}*/