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
    public String tree2str(TreeNode t) {
        if (t == null)
            return "";
        else if (t.left == null && t.right == null)
            return String.valueOf(t.val);
        else if (t.right == null)
            return t.val + "(" + this.tree2str(t.left) + ")";
        else
            return t.val + "(" + this.tree2str(t.left) + ")(" + this.tree2str(t.right) + ")";
    }
}
