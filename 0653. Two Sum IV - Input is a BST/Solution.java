import java.util.HashSet;
import java.util.Set;

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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> set = new HashSet<>();
        return this.dfs(root, k, set);
    }
    
    private boolean dfs(TreeNode root, int k, Set<Integer> visited) {
        if (root == null)
            return false;
        if (visited.contains(k - root.val))
            return true;
        visited.add(root.val);
        return this.dfs(root.left, k, visited) || this.dfs(root.right, k, visited);
    }
}
