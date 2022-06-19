import java.util.List;
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
    private final Map<Integer, Integer> counter = new HashMap<>();
    private int maxVal = 0;

    private int dfs(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int res = root.val + dfs(root.left) + dfs(root.right);
        counter.put(res, counter.getOrDefault(res, 0) + 1);
        maxVal = Math.max(maxVal, counter.get(res));
        return res;
    }

    public int[] findFrequentTreeSum(TreeNode root) {
        dfs(root);
        List<Integer> res = new ArrayList<>();
        for (Integer key : counter.keySet()) {
            if (counter.get(key) == maxVal) {
                res.add(key);
            }
        }
        return res.stream().mapToInt(e -> e).toArray();
    }
}
