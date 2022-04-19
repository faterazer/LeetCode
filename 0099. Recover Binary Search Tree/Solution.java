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
    public void recoverTree(TreeNode root) {
        TreeNode last = null, p1 = null, p2 = null;
        while (root != null) {
            if (last != null && last.val > root.val) {
                if (p1 == null) {
                    p1 = last;
                }
                p2 = root;
            }

            if (root.left == null) {
                last = root;
                root = root.right;
            } else {
                TreeNode predecessor = getPredecessor(root);
                if (predecessor.right == root) {
                    last = root;
                    predecessor.right = null;
                    root = root.right;
                } else {
                    predecessor.right = root;
                    root = root.left;
                }
            }
        }
        int temp = p1.val;
        p1.val = p2.val;
        p2.val = temp;
    }

    private TreeNode getPredecessor(TreeNode root) {
        TreeNode r = root.left;
        while (r.right != null && r.right != root) {
            r = r.right;
        }
        return r;
    }
}
