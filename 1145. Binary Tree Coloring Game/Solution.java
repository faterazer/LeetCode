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
    private TreeNode findNode(TreeNode root, int x) {
        if (root == null) {
            return null;
        }
        if (root.val == x) {
            return root;
        }
        TreeNode p = findNode(root.left, x);
        if (p != null) {
            return p;
        }
        return findNode(root.right, x);
    }

    private int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return countNodes(root.left) + countNodes(root.right) + 1;
    }
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        TreeNode nodeX = findNode(root, x);
        int a = countNodes(nodeX.left), b = countNodes(nodeX.right), c = n - a - b - 1, half = n / 2;
        return a > half || b > half || c > half;
    }
}
