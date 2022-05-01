import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private void iterNext(Deque<TreeNode> stack) {
        if (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            for (TreeNode p = node.right; p != null; p = p.left) {
                stack.push(p);
            }
        }
    }

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        Deque<TreeNode> stack1 = new ArrayDeque<>();
        Deque<TreeNode> stack2 = new ArrayDeque<>();
        for (TreeNode p = root1; p != null; p = p.left) {
            stack1.push(p);
        }
        for (TreeNode p = root2; p != null; p = p.left) {
            stack2.push(p);
        }

        List<Integer> res = new ArrayList<>();
        while (!stack1.isEmpty() || !stack2.isEmpty()) {
            if (stack2.isEmpty() || (!stack1.isEmpty() && stack1.peek().val <= stack2.peek().val)) {
                res.add(stack1.peek().val);
                iterNext(stack1);
            } else {
                res.add(stack2.peek().val);
                iterNext(stack2);
            }
        }
        return res;
    }
}
