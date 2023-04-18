#include <math.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int dfs(struct TreeNode* root, int min_val, int max_val)
{
    if (!root)
        return max_val - min_val;
    min_val = fmin(min_val, root->val);
    max_val = fmax(max_val, root->val);
    return fmax(dfs(root->left, min_val, max_val), dfs(root->right, min_val, max_val));
}

int maxAncestorDiff(struct TreeNode* root)
{
    return dfs(root, root->val, root->val);
}
