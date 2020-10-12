import java.util.Stack;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public int minDiffInBST(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root, pre = null;
        int ans = Integer.MAX_VALUE;
        while (node != null || !stack.empty()) {
            while (node != null) {
                stack.push(node);
                node = node.left;
            }
            node = stack.pop();
            if (pre != null)
                ans = Math.min(ans, node.val - pre.val);
            pre = node;
            node = node.right;
        }
        return ans;
    }
}
