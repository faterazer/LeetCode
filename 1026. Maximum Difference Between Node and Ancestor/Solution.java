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
    private int dfs(TreeNode root, int minVal, int maxVal) {
        if (root == null) {
            return maxVal - minVal;
        }
        minVal = Math.min(minVal, root.val);
        maxVal = Math.max(maxVal, root.val);
        return Math.max(dfs(root.left, minVal, maxVal), dfs(root.right, minVal, maxVal));
    }

    public int maxAncestorDiff(TreeNode root) {
        return dfs(root, root.val, root.val);
    }
}
