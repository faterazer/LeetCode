import java.util.ArrayList;
import java.util.List;

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
    private int depth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return Math.max(depth(root.left), depth(root.right)) + 1;
    }

    private void helper(TreeNode root, int l, int r, List<List<String>> res, int d) {
        if (root == null || l > r) {
            return;
        }
        int m = l + ((r - l) >> 1);
        res.get(d).set(m, String.valueOf(root.val));
        helper(root.left, l, m - 1, res, d + 1);
        helper(root.right, m + 1, r, res, d + 1);
    }

    public List<List<String>> printTree(TreeNode root) {
        int m = depth(root), n = (int) (Math.pow(2, m) - 1);
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<String> row = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                row.add("");
            }
            res.add(row);
        }
        helper(root, 0, n - 1, res, 0);
        return res;
    }
}
