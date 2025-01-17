//Mehmet Ilbey Angur - Section 1 - 22303555

#include "Queue.h"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() 
{
    while (!isEmpty()) 
    {
        dequeue();
    }
}

void Queue::enqueue(Block* item) 
{
    QueueNode* newNode = new QueueNode(item);
    if (isEmpty()) 
    {
        front = rear = newNode;
    } else 
    {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

Block* Queue::dequeue() 
{
    if (isEmpty()) 
    {
        std::cout << "Queue is empty."<< std::endl;
    }

    QueueNode* oldFront = front;
    Block* data = oldFront->data;
    front = front->next;
    delete oldFront;
    size--;

    if (isEmpty()) 
    {
        rear = nullptr;
    }

    return data;
}

bool Queue::isEmpty() const 
{
    return size == 0;
}

int Queue::getSize() const 
{
    return size;
}
