struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode *root) {
    if (!root)
        return 0;
    if (root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
