class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public boolean isBalanced(TreeNode root) {
        return this.depth(root) != -1;
    }

    private int depth(TreeNode root) {
        if (root == null)
            return 0;
        int left = this.depth(root.left);
        int right = this.depth(root.right);
        if (left == -1 || right == -1 || Math.abs(left - right) > 1)
            return -1;
        return Math.max(left, right) + 1;
    }
}
