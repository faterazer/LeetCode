import java.util.HashMap;
import java.util.Map;

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
    private final Map<Integer, Integer> map = new HashMap<>();
    private int res = 0;

    private void dfs(TreeNode root, int index, int depth) {
        if (root == null) {
            return;
        }
        if (!map.containsKey(depth)) {
            map.put(depth, index);
        }
        res = Math.max(res, index - map.get(depth) + 1);
        dfs(root.left, index << 1, depth + 1);
        dfs(root.right, index << 1 | 1, depth + 1);
    }

    public int widthOfBinaryTree(TreeNode root) {
        dfs(root, 1, 0);
        return res;
    }
}
