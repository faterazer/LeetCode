#include <math.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int helper(struct TreeNode *root, int *tilt)
{
    if (!root)
        return 0;
    int left = helper(root->left, tilt);
    int right = helper(root->right, tilt);
    *tilt += abs(left - right);
    return left + right + root->val;
}

int findTilt(struct TreeNode *root)
{
    int res = 0;
    helper(root, &res);
    return res;
}
