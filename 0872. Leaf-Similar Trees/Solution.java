import java.util.Stack;

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        Stack<TreeNode> s1 = new Stack<>(), s2 = new Stack<>();
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty() && !s2.empty()) {
            if (nextLeaf(s1) != nextLeaf(s2)) {
                return false;
            }
        }
        return s1.empty() && s2.empty();
    }

    private int nextLeaf(Stack<TreeNode> stack) {
        while (!stack.empty()) {
            TreeNode p = stack.pop();
            if (p.right != null)
                stack.push(p.right);
            if (p.left != null)
                stack.push(p.left);
            if (p.left == null && p.right == null)
                return p.val;
        }
        return -1;
    }
}
