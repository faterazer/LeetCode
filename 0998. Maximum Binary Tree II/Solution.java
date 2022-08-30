public class TreeNode {
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
    public TreeNode insertIntoMaxTree(TreeNode root, int val) {
        TreeNode node = new TreeNode(val), cur = root;
        if (root.val < val) {
            node.left = root;
            return node;
        }
        while (cur.right != null && cur.right.val > val) {
            cur = cur.right;
        }
        node.left = cur.right;
        cur.right = node;
        return root;
    }
}
