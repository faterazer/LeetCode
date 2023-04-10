import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;

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
    public int[] nextLargerNodes(ListNode head) {
        List<Integer> res = new ArrayList<>();
        Deque<Integer> stack = new LinkedList<>();
        while (head != null) {
            while (!stack.isEmpty() && head.val > res.get(stack.peek())) {
                res.set(stack.pop(), head.val);
            }
            stack.push(res.size());
            res.add(head.val);
            head = head.next;
        }
        while (!stack.isEmpty()) {
            res.set(stack.pop(), 0);
        }
        return res.stream().mapToInt(i -> i).toArray();
    }
}
