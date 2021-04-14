import java.util.Stack;

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
    private int ans = Integer.MAX_VALUE;
    private Integer pre = null;

    private void inOrder(TreeNode root) {
        if (root == null)
            return;
        inOrder(root.left);
        if (pre != null)
            this.ans = Math.min(ans, Math.abs(root.val - pre));
        pre = root.val;
        inOrder(root.right);
    }

    private TreeNode getSuccessor(TreeNode root) {
        TreeNode p = root.left;
        while (p.right != null && p.right != root) {
            p = p.right;
        }
        return p;
    }

    public int getMinimumDifference_MK1(TreeNode root) {
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

    public int getMinimumDifference_MK2(TreeNode root) {
        inOrder(root);
        return ans;
    }

    public int getMinimumDifference_MK3(TreeNode root) {
        int res = Integer.MAX_VALUE;
        TreeNode pre = null;
        while (root != null) {
            if (pre != null) {
                res = Math.min(res, Math.abs(root.val - pre.val));
            }
            if (root.left == null) {
                pre = root;
                root = root.right;
            } else {
                TreeNode succ = getSuccessor(root);
                if (succ.right == root) {
                    succ.right = null;
                    pre = root;
                    root = root.right;
                } else {
                    succ.right = root;
                    root = root.left;
                }
            }
        }
        return res;
    }
}
