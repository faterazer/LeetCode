class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

class Solution {
    // Iterative
    public ListNode reverseList_MK1(ListNode head) {
        ListNode newHead = new ListNode(0);
        while (head != null) {
            ListNode tp = head;
            head = head.next;
            tp.next = newHead.next;
            newHead.next = tp;
        }
        return newHead.next;
    }

    // Recursive
    public ListNode reverseList_MK2(ListNode head) {
        if (head != null && head.next != null) {
            ListNode tempHead = reverseList_MK2(head.next);
            head.next.next = head;
            head.next = null;
            return tempHead;
        } else {
            return head;
        }
    }
}
