#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack(unsigned int size);
	~Stack();
	
	bool push(int);
    int pop();
	int top();
	bool full();
	bool empty();
private:
    unsigned int capacity;
	unsigned int size;
    int *arr;
};

#endif