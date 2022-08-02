class MyCircularQueue {
    int[] queue;
    int front = 0, rear = 1, len;

    public MyCircularQueue(int k) {
        queue = new int[k + 1];
        len = k + 1;
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        } else {
            queue[rear] = value;
            rear = (rear + 1) % len;
            return true;
        }
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        } else {
            front = (front + 1) % len;
            return true;
        }
    }

    public int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return queue[(front + 1) % len];
        }
    }

    public int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return queue[(rear - 1 + len) % len];
        }
    }

    public boolean isEmpty() {
        return (front + 1) % len == rear;
    }

    public boolean isFull() {
        return front == rear;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */
