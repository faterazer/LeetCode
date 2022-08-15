#include <vector>
using namespace std;

class MyCircularDeque {
public:
    MyCircularDeque(int k)
        : Q(k)
    {
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        front = (front - 1 + Q.size()) % Q.size();
        Q[front] = value;
        ++size;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        Q[rear] = value;
        rear = (rear + 1) % Q.size();
        ++size;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % Q.size();
        --size;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
        rear = (rear - 1 + Q.size()) % Q.size();
        --size;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return Q[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return Q[(rear - 1 + Q.size()) % Q.size()];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == Q.size();
    }

private:
    vector<int> Q;
    int front = 0, rear = 0, size = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
