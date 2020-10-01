import java.util.Arrays;
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
    public int findSecondMinimumValue(TreeNode root) {
        List<Integer> list = Arrays.asList(root.val, -1);
        this.dfs(root, list);
        return list.get(1);
    }

    private void dfs(TreeNode root, List<Integer> min) {
        if (root == null)
            return;
        if (root.val > min.get(0)) {
            if (min.get(1) == -1)
                min.set(1, root.val);
            else
                min.set(1, Math.min(root.val, min.get(1)));
        }
        this.dfs(root.left, min);
        this.dfs(root.right, min);
    }
}
