struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode *root, int min[])
{
    if (!root)
        return;
    if (root->val > min[0]) {
        if (min[1] == -1)
            min[1] = root->val;
        else
            min[1] = min[1] < root->val ? min[1] : root->val;
    }
    dfs(root->left, min);
    dfs(root->right, min);
}

int findSecondMinimumValue(struct TreeNode *root)
{
    int min[] = {root->val, -1};
    dfs(root, min);
    return min[1];
}
