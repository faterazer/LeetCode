class Solution {
    public boolean isSubtree_MK1(TreeNode s, TreeNode t) {
        if (s == null)
            return false;
        return this.isSame(s, t) || this.isSubtree_MK1(s.left, t) || this.isSubtree_MK1(s.right, t);
    }

    private boolean isSame(TreeNode s, TreeNode t) {
        if (s == null && t == null)
            return true;
        else if (s == null || t == null || s.val != t.val)
            return false;
        else
            return this.isSame(s.left, t.left) && this.isSame(s.right, t.right);
    }

    public boolean isSubtree_MK2(TreeNode s, TreeNode t) {
        String ss = this.preOrder(s);
        String ts = this.preOrder(t);
        return ss.contains(ts);
    }

    private String preOrder(TreeNode root) {
        if (root == null)
            return "null";
        return "#" + root.val + this.preOrder(root.left) + this.preOrder(root.right);
    }
}
