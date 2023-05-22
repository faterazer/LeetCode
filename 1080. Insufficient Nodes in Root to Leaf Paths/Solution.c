#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* sufficientSubset(struct TreeNode* root, int limit)
{
    if (!root)
        return NULL;
    if (!root->left && !root->right)
        return root->val < limit ? NULL : root;
    root->left = sufficientSubset(root->left, limit - root->val);
    root->right = sufficientSubset(root->right, limit - root->val);
    return !root->left && !root->right ? NULL : root;
}
