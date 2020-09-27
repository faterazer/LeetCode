class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) { 
        if (p.val > q.val)
            return this.lowestCommonAncestor(root, q, p);
        if (p.val <= root.val && q.val >= root.val)
            return root;
        else if (q.val <= root.val)
            return this.lowestCommonAncestor(root.left, p, q);
        else
            return this.lowestCommonAncestor(root.right, p, q);
    }
}
