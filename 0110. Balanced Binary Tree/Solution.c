#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int depth(struct TreeNode *root)
{
    if (!root)
        return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;
    return fmax(l, r) + 1;
}

bool isBalanced(struct TreeNode *root)
{
    return depth(root) != -1;
}
