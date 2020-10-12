#include <limits.h>
#include <math.h>

#define min(a, b) ((a < b) ? (a) : (b))

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inOrder(struct TreeNode *root, struct TreeNode **pre, int *ans)
{
    if (root->left)
        inOrder(root->left, pre, ans);
    if (*pre)
        *ans = min(*ans, root->val - (*pre)->val);
    *pre = root;
    if (root->right)
        inOrder(root->right, pre, ans);
}

int getMinimumDifference(struct TreeNode *root)
{
    struct TreeNode *pre = NULL;
    int ans = INT_MAX;
    inOrder(root, &pre, &ans);
    return ans;
}
