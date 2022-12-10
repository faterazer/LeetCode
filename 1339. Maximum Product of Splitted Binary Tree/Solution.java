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
    private long sum = 0, best = 0;

    private int treeSum(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return root.val + treeSum(root.left) + treeSum(root.right);
    }

    private int helper(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int cur = root.val + helper(root.left) + helper(root.right);
        if (Math.abs(cur * 2L - sum) < Math.abs(best * 2 - sum)) {
            best = cur;
        }
        return cur;
    }

    public int maxProduct(TreeNode root) {
        sum = treeSum(root);
        helper(root);
        return Math.toIntExact(best * (sum - best) % 1000000007);
    }
}
