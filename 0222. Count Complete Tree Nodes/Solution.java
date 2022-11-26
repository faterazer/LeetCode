class Solution {
    private int leftHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + leftHeight(root.left);
    }

    private int rightHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + rightHeight(root.right);
    }

    public int countNodes(TreeNode root) {
        int lh = leftHeight(root), rh = rightHeight(root);
        if (lh == rh) {
            return (1 << lh) - 1;
        }
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
