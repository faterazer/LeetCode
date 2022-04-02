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
    private TreeNode builder(int[] preorder, int idx, int[] inorder, int l, int r) {
        if (idx < 0 || idx >= preorder.length || l > r) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[idx]);
        int mid = l;
        while (mid <= r && inorder[mid] != preorder[idx]) {
            mid += 1;
        }
        root.left = builder(preorder, idx + 1, inorder, l, mid - 1);
        root.right = builder(preorder, idx + mid - l + 1, inorder, mid + 1, r);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return builder(preorder, 0, inorder, 0, inorder.length - 1);
    }
}
