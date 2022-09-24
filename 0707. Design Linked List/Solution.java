class LinkNode {
    public int val;
    public LinkNode next;

    LinkNode(int val) {
        this.val = val;
        next = null;
    }

    LinkNode(int val, LinkNode next) {
        this.val = val;
        this.next = next;
    }
}

class MyLinkedList {
    private final LinkNode head;
    private LinkNode tail;

    public MyLinkedList() {
        head = new LinkNode(0);
        tail = head;
    }

    public int get(int index) {
        if (index < 0 || index >= head.val) {
            return -1;
        }
        LinkNode p = head.next;
        while (index-- != 0) {
            p = p.next;
        }
        return p.val;
    }

    public void addAtHead(int val) {
        head.next = new LinkNode(val, head.next);
        ++head.val;
        if (tail == head) {
            tail = head.next;
        }
    }

    public void addAtTail(int val) {
        LinkNode p = new LinkNode(val, tail.next);
        tail.next = p;
        tail = p;
        ++head.val;
    }

    public void addAtIndex(int index, int val) {
        if (index > head.val) {
            return;
        }

        if (index < 0) {
            addAtHead(val);
        } else if (index == head.val) {
            addAtTail(val);
        } else {
            LinkNode pre = head;
            while (index-- != 0) {
                pre = pre.next;
            }
            pre.next = new LinkNode(val, pre.next);
            ++head.val;
        }
    }

    public void deleteAtIndex(int index) {
        if (index < 0 || index >= head.val) {
            return;
        }
        LinkNode pre = head;
        while (index-- != 0) {
            pre = pre.next;
        }
        LinkNode p = pre.next;
        if (p == tail) {
            tail = pre;
        }
        pre.next = p.next;
        --head.val;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
