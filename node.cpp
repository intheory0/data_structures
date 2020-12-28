#include "node.h"

Node::Node() // default constructor
{
	this->value = 0;
	this->height = 1;
	this->left = this->right = nullptr;
}

Node::Node(int value, Node *left, Node *right) // constructor with params
{
	this->value = value;
	this->left = left;
	this->right = right;
	this->height = 1;
}

Node::Node(Node &node) // copy constructor
{
	this->value = node.value;
	this->left = node.left;
	this->right = node.right;
	this->height = node.height;
}