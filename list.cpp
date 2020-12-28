#include "list.h"
#include "node.h"

List::List()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

List::~List()
{
	clear();
}

void List::push_front(int value)
{
    Node *n = new Node(value);
	if (!n)
		return ;
    n->right = head;
    if (head != NULL)
        head->left = n;
	else
		tail = n;
    head = n;
    size++;
}

void List::push_back(int value)
{
    Node *n = new Node(value);
    if (!n)
		return ;
    n->left = tail;
    if (tail != NULL)
        tail->right = n;
    else
        head = n;
    tail = n;
    size++;
}

size_t List::get_size()
{
    /*Node *node = head;
    size_t res = 0;
    while (node)
    {
        node = node->right;
        res++;
    }
    return res;*/
	return size;
}

Node* List::at(size_t index)
{
    Node *node = head;
    while (node && index)
    {
        node = node->right;
        index--;
    }
    return node;
}

void List::foreach(void (*f)(int))
{
    Node *node = head;
    while (node)
    {
        f(node->value);
        node = node->right;
    }
}

void List::sorted_insert(int (*cmp)(int, int), int data)
{
    Node *node = head;
    Node *insert_node = new Node(data);
	
    while (node && cmp(node->value, data) < 0)
        node = node->right;
    if (head == NULL)
		head = tail = insert_node;
	else if (node == head)
    {
        insert_node->right = node;
		node->left = insert_node;
        head = insert_node;
    }
    else if (node == NULL)
    {
        insert_node->left = tail;
		tail->right = insert_node;
        tail = insert_node;
    }
    else
    {
        insert_node->right = node;
        insert_node->left = node->left;
    }
	size++;
}

void List::clear()
{
    Node *node = head;
    while (node)
    {
        Node *next = node->right;
        delete node;
        node = next;
    }
}

Node* List::front()
{
    return head;
}

Node* List::last()
{
    return tail;
}