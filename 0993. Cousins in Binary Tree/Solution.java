import java.util.LinkedList;
import java.util.Queue;

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
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode p = queue.poll();
                if (p.val == x) {
                    x = 0;
                } else if (p.val == y) {
                    y = 0;
                }
                if (p.left != null && p.right != null && ((p.left.val == x && p.right.val == y) || (p.left.val == y && p.right.val == x))) {
                    return false;
                }
                if (p.left != null) {
                    queue.offer(p.left);
                }
                if (p.right != null) {
                    queue.offer(p.right);
                }
            }
            if (x == 0 && y == 0) {
                return true;
            } else if (x == 0 || y == 0) {
                return false;
            }
        }
        return false;
    }
}
