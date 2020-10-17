#include <stddef.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *searchBST(struct TreeNode *root, int val)
{
    if (!root)
        return NULL;
    if (val < root->val)
        return searchBST(root->left, val);
    else if (val > root->val)
        return searchBST(root->right, val);
    else
        return root;
}
