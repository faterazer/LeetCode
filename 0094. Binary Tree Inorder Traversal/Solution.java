import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
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
    /**
     * Iterating method using Stack
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    public List<Integer> inorderTraversal_MK1(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        Deque<TreeNode> stack = new ArrayDeque<>();
        while (root != null || !stack.isEmpty()) {
            while (root != null) {
                stack.addLast(root);
                root = root.left;
            }
            root = stack.removeLast();
            res.add(root.val);
            root = root.right;
        }
        return res;
    }

    private TreeNode getSuccessor(TreeNode root) {
        TreeNode successor = root.left;
        while (successor.right != null && successor.right != root) {
            successor = successor.right;
        }
        return successor;
    }

    /**
     * Morris Traversal
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    public List<Integer> inorderTraversal_MK2(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        while (root != null) {
            if (root.left != null) {
                TreeNode successor = getSuccessor(root);
                if (successor.right == root) {
                    successor.right = null;
                    res.add(root.val);
                    root = root.right;
                } else {
                    successor.right = root;
                    root = root.left;
                }
            } else {
                res.add(root.val);
                root = root.right;
            }
        }
        return res;
    }
}
