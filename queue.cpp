class Part
{
public:
    int value;
    Part *next;
    Part();
    Part(int value, Part *next = nullptr);
};

Part::Part()
{
    this->value = 0;
    this->next = nullptr;
}

Part::Part(int value, Part *next)
{
    this->value = value;
    this->next = next;
}


class Queue
{
private:
    Part *root;
public:
    Queue();
    Queue(Part *root);
    void push(int);
    int pop();
	int top();
};

Queue::Queue()
{
    this->root = nullptr;
}

Queue::Queue(Part *root)
{
    this->root = root;
}

void Queue::push(int value)
{
    Part *cur = root;
    Part *part = new Part(value);

	if (cur) 
	{
		while (cur->next != nullptr)
        	cur = cur->next;
    	cur->next = part;
	}
	else
		root = part;
}

int Queue::top()
{
    if (root)
        return root->value;
    return -1;
}

int Queue::pop()
{
    if (root)
    {
        int value = root->value;
        Part *part = root->next;
		delete root;
        root = part;
        return value;
    }
    return -1;
}
