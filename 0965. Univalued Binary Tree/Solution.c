#include <stdbool.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool traverse(struct TreeNode *root, struct TreeNode *pre)
{
    if (!root)
        return true;
    else if (pre && root->val != pre->val)
        return false;
    else 
        return traverse(root->left, root) && traverse(root->right, root);
}

bool isUnivalTree(struct TreeNode *root)
{
    return traverse(root, NULL);
}
