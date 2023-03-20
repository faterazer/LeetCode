import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
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
    private void preorder(TreeNode root, List<Integer> res) {
        if (root == null) {
            return;
        }
        res.add(root.val);
        preorder(root.left, res);
        preorder(root.right, res);
    }

    public List<Integer> preorderTraversal_MK1(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        preorder(root, res);
        return res;
    }

    public List<Integer> preorderTraversal_MK2(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }

        Deque<TreeNode> stack = new LinkedList<>();
        stack.add(root);
        while (!stack.isEmpty()) {
            TreeNode p = stack.pop();
            res.add(p.val);
            if (p.right != null) {
                stack.push(p.right);
            }
            if (p.left != null) {
                stack.push(p.left);
            }
        }
        return res;
    }

    private TreeNode getSuccessor(TreeNode root) {
        TreeNode res = root.left;
        while (res.right != null && res.right != root) {
            res = res.right;
        }
        return res;
    }

    public List<Integer> preorderTraversal_MK3(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left != null) {
                TreeNode successor = getSuccessor(cur);
                if (successor.right == cur) {
                    successor.right = null;
                    cur = cur.right;
                } else {
                    res.add(cur.val);
                    successor.right = cur;
                    cur = cur.left;
                }
            } else {
                res.add(cur.val);
                cur = cur.right;
            }
        }
        return res;
    }
}
