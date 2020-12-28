#ifndef LIST_H
#define LIST_H

#include <stddef.h>

class List
{
private:
    Node *head;
	Node *tail;
	size_t size;

public:
    List();
    ~List();

	void push_front(int value);
	void push_back(int value);
	size_t get_size();
	Node *at(size_t index);
	void foreach(void (*f)(int));
	void sorted_insert(int (*cmp)(int, int), int data);
	void clear();
	Node *front();
	Node *last();
};

#endif