struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int dfs(struct TreeNode *root, int cur)
{
    if (!root)
        return 0;
    cur = cur << 1 | root->val;
    return !root->left && !root->right ? cur : dfs(root->left, cur) + dfs(root->right, cur);
}

int sumRootToLeaf(struct TreeNode *root)
{
    return dfs(root, 0);
}
