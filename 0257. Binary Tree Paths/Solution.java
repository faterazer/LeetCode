import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ret = new ArrayList<>();
        if (root != null)
            this.dfs(root, ret, "");
        return ret;
    }

    private void dfs(TreeNode root, List<String> paths, String path) {
        path += root.val;
        if (root.left == null && root.right == null) {
            paths.add(path.toString());
            return;
        }
        if (root.left != null)
            this.dfs(root.left, paths, path + "->");
        if (root.right != null)
            this.dfs(root.right, paths, path + "->");
    }
}
