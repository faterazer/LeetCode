class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        for (Node p = head; p != null; p = p.next.next) {
            Node q = new Node(p.val);
            q.next = p.next;
            p.next = q;
        }
        for (Node p = head; p != null; p = p.next.next) {
            if (p.random != null) {
                p.next.random = p.random.next;
            }
        }
        Node r = head.next;
        for (Node p = head; p != null; p = p.next) {
            Node q = p.next;
            p.next = q.next;
            if (p.next != null) {
                q.next = p.next.next;
            }
        }
        return r;
    }
}
