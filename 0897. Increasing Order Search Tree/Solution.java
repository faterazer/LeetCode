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
    public TreeNode increasingBST(TreeNode root) {
        return inOrder(root, null);
    }

    private TreeNode inOrder(TreeNode root, TreeNode tail) {
        if (root == null)
            return tail;
        TreeNode head = inOrder(root.left, root);
        root.left = null;
        root.right = inOrder(root.right, tail);
        return head;
    }
}
