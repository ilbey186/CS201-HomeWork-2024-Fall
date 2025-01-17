//Mehmet Ilbey Angur - Section 1 - 22303555

#ifndef QUEUE_H
#define QUEUE_H

#include "Block.h"

class QueueNode {
public:
    Block* data; 
    QueueNode* next;

    QueueNode(Block* data, QueueNode* next = nullptr)
        : data(data), next(next) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;

public:
    Queue();
    ~Queue();

    void enqueue(Block* item);
    Block* dequeue();
    bool isEmpty() const;
    int getSize() const;
};

#endif // QUEUE_H

