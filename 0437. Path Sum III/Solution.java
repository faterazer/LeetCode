import java.util.HashMap;
import java.util.Map;

class TreeNode {
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
    public int pathSum(TreeNode root, int sum) {
        Map<Integer, Integer> pathSum = new HashMap<>();
        pathSum.put(0, 1);
        return this.pathSum(root, sum, pathSum, 0);
    }

    private int pathSum(TreeNode root, int target, Map<Integer, Integer> pathSum, int curSum)
    {
        if (root == null)
            return 0;
        curSum += root.val;
        int res = pathSum.getOrDefault(curSum - target, 0);
        pathSum.put(curSum, pathSum.getOrDefault(curSum, 0) + 1);
        res += this.pathSum(root.left, target, pathSum, curSum) + this.pathSum(root.right, target, pathSum, curSum);
        pathSum.put(curSum, pathSum.get(curSum) - 1);
        return res;
    }
}
