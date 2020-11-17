struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode *root, int low, int high)
{
    if (!root)
        return 0;
    if (root->val < low)
        return rangeSumBST(root->right, low, high);
    if (root->val > high)
        return rangeSumBST(root->left, low, high);
    return rangeSumBST(root->left, low, high) + root->val + rangeSumBST(root->right, low, high);
}
