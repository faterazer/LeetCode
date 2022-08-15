class MyCircularDeque {

    private final int[] buff;
    private int front;
    private int rear = 0;
    private int size = 0;

    public MyCircularDeque(int k) {
        buff = new int[k];
        front = k - 1;
    }

    public boolean insertFront(int value) {
        if (isFull()) {
            return false;
        } else {
            buff[front] = value;
            front = (front - 1 + buff.length) % buff.length;
            ++size;
            return true;
        }
    }

    public boolean insertLast(int value) {
        if (isFull()) {
            return false;
        } else {
            buff[rear] = value;
            rear = (rear + 1) % buff.length;
            ++size;
            return true;
        }
    }

    public boolean deleteFront() {
        if (isEmpty()) {
            return false;
        } else {
            front = (front + 1) % buff.length;
            --size;
            return true;
        }
    }

    public boolean deleteLast() {
        if (isEmpty()) {
            return false;
        } else {
            rear = (rear - 1 + buff.length) % buff.length;
            --size;
            return true;
        }
    }

    public int getFront() {
        if (isEmpty()) {
            return -1;
        } else {
            return buff[(front + 1) % buff.length];
        }
    }

    public int getRear() {
        if (isEmpty()) {
            return -1;
        } else {
            return buff[(rear - 1 + buff.length) % buff.length];
        }
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == buff.length;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * boolean param_1 = obj.insertFront(value);
 * boolean param_2 = obj.insertLast(value);
 * boolean param_3 = obj.deleteFront();
 * boolean param_4 = obj.deleteLast();
 * int param_5 = obj.getFront();
 * int param_6 = obj.getRear();
 * boolean param_7 = obj.isEmpty();
 * boolean param_8 = obj.isFull();
 */
