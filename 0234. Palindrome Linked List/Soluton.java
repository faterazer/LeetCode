public class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head, fast = head, tp = null;
        ListNode half = new ListNode(0);
        half.next = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            tp = slow;
            slow = slow.next;
            tp.next = half.next;
            half.next = tp;
        }
        half = half.next;
        if (fast != null)
            slow = slow.next;
        for (; slow != null; half = half.next, slow = slow.next)
            if (half.val != slow.val)
                return false;
        return true;
    }
}
