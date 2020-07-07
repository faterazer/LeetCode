import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public boolean hasPathSum_MK1(TreeNode root, int sum) {
        if (root == null)
            return false;
        if (root.left == null && root.right == null)
            return root.val == sum;
        sum -= root.val;
        return hasPathSum_MK1(root.left, sum) || hasPathSum_MK1(root.right, sum);
    }

    public boolean hashPathSum_MK2(TreeNode root, int sum) {
        if (root == null)
            return false;

        Queue<TreeNode> nodeQue = new LinkedList<TreeNode>();
        Queue<Integer> sumQue = new LinkedList<Integer>();
        nodeQue.offer(root);
        sumQue.offer(root.val);
        while (!nodeQue.isEmpty()) {
            TreeNode node = nodeQue.poll();
            Integer curSum = sumQue.poll();
            if (node.left == null && node.right == null && curSum == sum)
                return true;
            if (node.right != null) {
                nodeQue.offer(node.right);
                sumQue.offer(curSum + node.right.val);
            }
            if (node.left != null) {
                nodeQue.offer(node.left);
                sumQue.offer(curSum + node.left.val);
            }
        }
        return false;
    }
}
