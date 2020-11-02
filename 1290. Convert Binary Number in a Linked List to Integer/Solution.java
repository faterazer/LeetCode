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
    public int getDecimalValue(ListNode head) {
        int ret = 0;
        for (; head != null; head = head.next)
            ret = ret << 1 | head.val;
        return ret;
    }
}
