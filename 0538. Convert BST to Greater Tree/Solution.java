import java.util.Stack;

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
     * Recursion approach 递归方法
     * Time complexity: O(n)
     * Space Complexity: O(n)
     */
    public TreeNode convertBST_MK1(TreeNode root) {
        inOrder(root, 0);
        return root;
    }

    private int inOrder(TreeNode root, int preSum) {
        if (root == null)
            return preSum;
        root.val += this.inOrder(root.right, preSum);
        preSum = root.val;
        return this.inOrder(root.left, preSum);
    }

    /**
     * Iteration with a Stack 迭代方法
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    public TreeNode convertBST_MK2(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        TreeNode p = root;
        int preSum = 0;
        while (!stack.empty() || p != null) {
            while (p != null) {
                stack.push(p);
                p = p.right;
            }
            p = stack.pop();
            p.val += preSum;
            preSum = p.val;
            p = p.left;
        }
        return root;
    }

    /**
     * Reverse Morris In-order Traversal 反转中序 Morris 遍历
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public TreeNode convertBST_MK3(TreeNode root) {
        TreeNode p = root;
        int preSum = 0;
        while (p != null) {
            if (p.right == null) {
                p.val += preSum;
                preSum = p.val;
                p = p.left;
            }
            else {
                TreeNode succ = getSuccessor(p);
                if (succ.left == null) {
                    succ.left = p;
                    p = p.right;
                }
                else {
                    succ.left = null;
                    p.val += preSum;
                    preSum = p.val;
                    p = p.left;
                }
            }
        }
        return root;
    }

    private TreeNode getSuccessor(TreeNode root) {
        TreeNode succ = root.right;
        while (succ.left != null && succ.left != root)
            succ = succ.left;
        return succ;
    }
}
