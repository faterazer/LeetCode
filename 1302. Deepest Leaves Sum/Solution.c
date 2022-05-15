struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void dfs(struct TreeNode* root, int depth, int *max_depth, int *res)
{
    if (!root)
        return;
    if (depth > *max_depth) {
        *max_depth = depth;
        *res = root->val;
    } else if (depth == *max_depth)
        *res += root->val;
    dfs(root->left, depth + 1, max_depth, res);
    dfs(root->right, depth + 1, max_depth, res);
}

int deepestLeavesSum(struct TreeNode* root)
{
    int max_depth = -1, res = 0;
    dfs(root, 0, &max_depth, &res);
    return res;
}
