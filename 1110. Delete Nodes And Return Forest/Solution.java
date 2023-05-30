import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
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
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Set<Integer> delSet = new HashSet<>();
        for (int x : to_delete) {
            delSet.add(x);
        }
        List<TreeNode> res = new ArrayList<>();
        dfs(root, delSet, res, true);
        return res;
    }

    private TreeNode dfs(TreeNode node, Set<Integer> delSet, List<TreeNode> res, boolean isRoot) {
        if (node == null) {
            return null;
        }
        if (delSet.contains(node.val)) {
            dfs(node.left, delSet, res, true);
            dfs(node.right, delSet, res, true);
            return null;
        }
        if (isRoot) {
            res.add(node);
        }
        node.left = dfs(node.left, delSet, res, false);
        node.right = dfs(node.right, delSet, res, false);
        return node;
    }
}
