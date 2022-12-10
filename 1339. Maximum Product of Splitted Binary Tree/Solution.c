#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int treeSum(struct TreeNode* root)
{
    if (!root)
        return 0;
    return root->val + treeSum(root->left) + treeSum(root->right);
}

int helper(struct TreeNode* root, int sum, int* res)
{
    if (!root)
        return 0;
    int cur = root->val + helper(root->left, sum, res) + helper(root->right, sum, res);
    if (abs(cur * 2 - sum) < abs(*res * 2 - sum))
        *res = cur;
    return cur;
}

int maxProduct(struct TreeNode* root)
{
    int P = 1e9 + 7;
    int sum = treeSum(root);
    int res = 0;
    helper(root, sum, &res);
    return (long long)res * (sum - res) % P;
}
