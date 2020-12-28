#ifndef HEAP_H
#define HEAP_H

class Heap 
{
private:
    int *arr;
    int size;
    int capacity;

public:
    Heap();
	Heap(Heap &h);
    Heap(int capacity);
	Heap(int *arr, int capacity);

    void insert(int value);
    void shift_down(int i);
    void shift_up(int i);
	void merge(Heap &h);

	void make_heap();
	int get_min();
};

#endif
