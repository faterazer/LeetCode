public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q) {
            return root;
        }
        TreeNode lp = lowestCommonAncestor(root.left, p, q);
        TreeNode rp = lowestCommonAncestor(root.right, p, q);
        if (lp != null && rp != null) {
            return root;
        } else if (lp != null || rp != null) {
            return lp == null ? rp : lp;
        } else {
            return null;
        }
    }
}
