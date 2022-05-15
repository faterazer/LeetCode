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
    private int max_depth = -1;
    private int res = 0;

    private void dfs(TreeNode root, int depth) {
        if (root == null) {
            return;
        }
        if (depth > max_depth) {
            max_depth = depth;
            res = root.val;
        } else if (depth == max_depth) {
            res += root.val;
        }
        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }

    public int deepestLeavesSum(TreeNode root) {
        dfs(root, 0);
        return res;
    }
}
