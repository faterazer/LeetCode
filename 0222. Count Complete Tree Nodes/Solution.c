struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int leftHeight(struct TreeNode* root)
{
    if (!root)
        return 0;
    return 1 + leftHeight(root->left);
}

int rightHeight(struct TreeNode* root)
{
    if (!root)
        return 0;
    return 1 + rightHeight(root->right);
}

int countNodes(struct TreeNode* root)
{
    if (!root)
        return 0;
    int lh = leftHeight(root), rh = rightHeight(root);
    if (lh == rh)
        return (1 << lh) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}
