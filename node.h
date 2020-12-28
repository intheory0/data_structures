#ifndef NODE_H
# define NODE_H

class Node
{
public:
	int value;
	int height;
	Node *left;
	Node *right;

	Node(); // default constructor
	Node(int value, Node *left = nullptr, Node *right = nullptr); // constructor with params

	Node(Node &node); // copy constructor
};

#endif