#include <vector>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k)
        : queue(k + 1)
        , len(k + 1)
    {
    }

    bool enQueue(int value)
    {
        if (isFull())
            return false;
        queue[rear] = value;
        rear = (rear + 1) % len;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % len;
        return true;
    }

    int Front()
    {
        if (isEmpty())
            return -1;
        return queue[(front + 1) % len];
    }

    int Rear()
    {
        if (isEmpty())
            return -1;
        return queue[(rear - 1 + len) % len];
    }

    bool isEmpty()
    {
        return (front + 1) % len == rear;
    }

    bool isFull()
    {
        return front == rear;
    }

private:
    vector<int> queue;
    int front = 0, rear = 1, len;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
