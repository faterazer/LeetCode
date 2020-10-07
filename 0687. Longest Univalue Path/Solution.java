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
    private int ans = 0;

    public int longestUnivaluePath(TreeNode root) {
        ans = 0;
        this.helper(root);
        return ans;
    }

    private int helper(TreeNode root) {
        if (root == null)
            return 0;
        int left = this.helper(root.left);
        int right = this.helper(root.right);
        int uniLeft = 0, uniRight = 0;
        if (root.left != null && root.left.val == root.val)
            uniLeft = left + 1;
        if (root.right != null && root.right.val == root.val)
            uniRight = right + 1;
        ans = Math.max(ans, uniLeft + uniRight);
        return Math.max(uniLeft, uniRight);
    }
}
