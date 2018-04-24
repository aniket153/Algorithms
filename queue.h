#pragma once

#define MAXQUEUE 100

class queue
{
public:
    queue();
    ~queue();
    int dequeue();
    void enqueue(int i);
    int front();
    bool isEmpty();
private:
    int q[MAXQUEUE];
    int fron;
    int rear;
};

