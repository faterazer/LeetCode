import java.util.LinkedList;
import java.util.Queue;

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
    public int maxLevelSum(TreeNode root) {
        int res = -1, maxSum = Integer.MIN_VALUE;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        for (int i = 1; !queue.isEmpty(); i++) {
            int tmpSum = 0;
            for (int j = queue.size(); j > 0; j--) {
                TreeNode node = queue.remove();
                tmpSum += node.val;
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            if (tmpSum > maxSum) {
                res = i;
                maxSum = tmpSum;
            }
        }
        return res;
    }
}
