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
    private int tilt = 0;

    public int findTilt(TreeNode root) {
        postOrder(root);
        return tilt;
    }

    private int postOrder(TreeNode root) {
        if (root == null)
            return 0;
        int left = this.postOrder(root.left);
        int right = this.postOrder(root.right);
        tilt += Math.abs(left - right);
        return root.val + left + right;
    }
}
