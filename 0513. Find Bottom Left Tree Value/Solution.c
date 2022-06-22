struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void dfs(struct TreeNode* root, int depth, int* res, int* max_depth)
{
    if (!root)
        return;
    if (depth > *max_depth) {
        *max_depth = depth;
        *res = root->val;
    }
    dfs(root->left, depth + 1, res, max_depth);
    dfs(root->right, depth + 1, res, max_depth);
}

int findBottomLeftValue(struct TreeNode* root)
{
    int max_depth = -1, res = root->val;
    dfs(root, 0, &res, &max_depth);
    return res;
}
