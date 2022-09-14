struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int dfs(struct TreeNode* root, int cnt)
{
    if (!root)
        return 0;
    cnt ^= 1 << (root->val - 1);
    int res = dfs(root->left, cnt) + dfs(root->right, cnt);
    if (!root->left && !root->right && (cnt & (cnt - 1)) == 0)
        ++res;
    return res;
}

int pseudoPalindromicPaths(struct TreeNode* root)
{
    return dfs(root, 0);
}
