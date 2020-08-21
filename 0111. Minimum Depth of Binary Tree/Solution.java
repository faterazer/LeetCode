class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    /**
     * DFS
     * Time complexity: O(n)
     * Average space complexity: O(lgn)
     * Worst space complexity: O(n)
     */
    public int minDepth_MK1(TreeNode root) {
        if (root == null)
            return 0;
        if (root.left == null)
            return this.minDepth_MK1(root.right) + 1;
        else if (root.right == null)
            return this.minDepth_MK1(root.left) + 1;
        else
            return Math.min(this.minDepth_MK1(root.left), this.minDepth_MK1(root.right)) + 1;
    }

    /**
     * BFS
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    public int minDepth_MK2(TreeNode root) {
        if (root == null)
            return 0;
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        int depth = 0;
        while (!queue.isEmpty()) {
            int n = queue.size();
            depth++;
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.poll();
                if (node.left == null && node.right == null)
                    return depth;
                if (node.left != null)
                    queue.offer(node.left);
                if (node.right != null)
                    queue.offer(node.right);
            }
        }
        return depth;
    }
}
