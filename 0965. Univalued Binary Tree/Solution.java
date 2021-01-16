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
    public boolean isUnivalTree(TreeNode root) {
        return traverse(root, null);
    }

    private boolean traverse(TreeNode root, TreeNode pre) {
        if (root == null)
            return true;
        else if (pre != null && pre.val != root.val)
            return false;
        else
            return traverse(root.left, root) && traverse(root.right, root);
    }
}
