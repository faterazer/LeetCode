#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool helper(struct TreeNode *root1, struct TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    else if (!root1 || !root2)
        return false;
    return root1->val == root2->val && helper(root1->left, root2->right) && helper(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root)
{
    if (!root)
        return true;
    return helper(root->left, root->right);
}
