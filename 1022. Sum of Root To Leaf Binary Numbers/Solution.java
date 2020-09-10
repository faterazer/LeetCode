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
    /**
     * Recursive Preorder Traversal.
     * Time complexity: O(N). N is a number of nodes.
     * Space complexity: O(H). H is a tree height.
     */
    public int sumRootToLeaf_MK1(TreeNode root) {
        return this.dfs(root, 0);
    }

    /**
     * Morris Preorder Traversal.
     * Time complexity: O(N). N is a number of nodes.
     * Space complexity: O(1).
     */
    public int sumRootToLeaf_MK2(TreeNode root) {
        int ret = 0, curNum = 0, steps = 0;
        while (root != null) {
            if (root.left == null) {
                curNum = (curNum << 1) + root.val;
                root = root.right;
                if (root == null)
                    ret += curNum;
            } else {
                TreeNode succ = root.left;
                steps = 1;
                while (succ.right != null && succ.right != root) {
                    succ = succ.right;
                    steps += 1;
                }
                if (succ.right == null) {
                    succ.right = root;
                    curNum = (curNum << 1) + root.val;
                    root = root.left;
                } else {
                    succ.right = null;
                    if (succ.left == null)
                        ret += curNum;
                    for (int i = 0; i < steps; i++)
                        curNum >>= 1;
                    root = root.right;
                }
            }
        }
        return ret;
    }

    private int dfs(TreeNode root, int curNum) {
        if (root == null)
            return 0;
        curNum = (curNum << 1) + root.val;
        return root.left == null && root.right == null ? curNum : this.dfs(root.left, curNum) + this.dfs(root.right, curNum);
    }
}
