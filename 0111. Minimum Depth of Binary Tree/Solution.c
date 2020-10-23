#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->left)
        return minDepth(root->right) + 1;
    if (!root->right)
        return minDepth(root->left) + 1;
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}
