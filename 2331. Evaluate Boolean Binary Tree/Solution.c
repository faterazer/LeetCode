#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool evaluateTree(struct TreeNode* root)
{
    if (!root->left)
        return root->val;
    if (root->val == 2)
        return evaluateTree(root->left) || evaluateTree(root->right);
    return evaluateTree(root->left) && evaluateTree(root->right);
}
