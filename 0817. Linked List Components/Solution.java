import java.util.HashSet;
import java.util.Set;

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
    public int numComponents(ListNode head, int[] nums) {
        Set<Integer> subset = new HashSet<>();
        for (int e : nums) {
            subset.add(e);
        }
        int res = 0, is_component = 0;
        while (head != null) {
            if (subset.contains(head.val)) {
                is_component = 1;
            } else {
                res += is_component;
                is_component = 0;
            }
            head = head.next;
        }
        return res + is_component;
    }
}
