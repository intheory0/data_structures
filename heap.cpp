#include "heap.h"
#include <algorithm>

Heap::Heap()
{
    capacity = 16;
    size = 0;
    arr = new int[capacity];
}

Heap::Heap(int capacity)
{
    this->capacity = capacity;
    size = 0;
    arr = new int[capacity];
}

Heap::Heap(Heap &h)
{
	this->capacity = h.capacity;
    size = 0;
    arr = new int[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		arr[i] = h.arr[i];
	}
}

Heap::Heap(int *arr_in, int capacity)
{
    this->capacity = capacity;
    size = 0;
    arr = new int[capacity];
	for (int i = 0; i < capacity; ++i)
	{
		arr[i] = arr_in[i];
	}
	make_heap();
}

void Heap::make_heap()
{
	for (int i = capacity / 2; i >= 0; ++i)
	{
		shift_down(i);
	}
}

int Heap::get_min()
{
	if (arr)
    	return arr[0];
	return 0;
}

void Heap::shift_up(int j)
{
    while (arr[j] < arr[(j - 1) / 2])
    {
        std::swap(arr[j], arr[(j - 1) / 2]);
        j = (j - 1) / 2;
    }
}

void Heap::shift_down(int i)
{
	while (2 * i + 1 < size)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
		
        if ((right < size) && (arr[right] < arr[left]))
            j = right;
        if (arr[i] <= arr[j])
            break;
        std::swap(arr[i], arr[j]);
        i = j;
    }
}

void Heap::insert(int value)
{
    if (capacity > size)
    {
        arr[size] = value;
        size++;
        shift_up(size - 1);
    }
}

/*void Heap::merge(Heap &h)
{
	arr = (int*)realloc(arr, (capacity + h.capacity) * sizeof(int));
    for(int i = 0; i <= h.size; ++i)
        insert(h.arr[i]);
}*/

void Heap::merge(Heap &h)
{
    arr = (int*)realloc(arr, (capacity + h.capacity) * sizeof(int));
    for(int i = 0; i <= h.size; ++i)
        arr[size - 1 + i] = h.arr[i];
	size += h.size;
    make_heap();
}