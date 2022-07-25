import java.util.ArrayDeque;
import java.util.Deque;

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

class CBTInserter {
    private final TreeNode root;
    private final Deque<TreeNode> queue = new ArrayDeque<>();

    public CBTInserter(TreeNode root) {
        this.root = root;
        queue.offer(root);
        while (queue.getFirst().right != null) {
            TreeNode node = queue.pollFirst();
            if (node.left != null) {
                queue.offer(node.left);
            }
            if (node.right != null) {
                queue.offer(node.right);
            }
        }
        if (queue.peekFirst().left != null) {
            queue.offer(queue.peekFirst().left);
        }
    }

    public int insert(int val) {
        TreeNode node = new TreeNode(val);
        queue.offer(node);
        int res = queue.getFirst().val;
        if (queue.getFirst().left == null) {
            queue.getFirst().left = node;
        } else {
            queue.pollFirst().right = node;
        }
        return res;
    }

    public TreeNode get_root() {
        return root;
    }
}

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(val);
 * TreeNode param_2 = obj.get_root();
 */
