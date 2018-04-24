#include "queue.h"

queue::queue()
{
    fron = 0;
    rear = 0;
}


queue::~queue()
{
}

int queue::dequeue()
{
    return q[rear--];
}

void queue::enqueue(int i)
{
    q[fron++] = i;
}

int queue::front()
{
    return q[fron];
}

bool queue::isEmpty()
{
    return fron == rear;
}
