#include "stack.h"

Stack::Stack(unsigned int capacity)
{
    this->size = 0;
    this->capacity = capacity;
    this->arr = new int[size];
}

Stack::~Stack()
{
	delete [] arr;
}
	
bool Stack::push(int value)
{
    if (capacity != size)
    {
        arr[size] = value;
        size++;
		return true;
    }
	return false;
}

int Stack::pop()
{
    if (size)
    {
		size--;
    	return arr[size];
	}
	return -1;
}

int Stack::top()
{
    if (size)
        return arr[size - 1];
    return -1;
}

bool Stack::full()
{
    return (capacity == size);
}

bool Stack::empty()
{
	return (size == 0);
}