#define max(a, b) ((a > b) ? (a) : (b))

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int helper(struct TreeNode *root, int *ans)
{
    if (!root)
        return 0;
    int left = helper(root->left, ans);
    int right = helper(root->right, ans);
    int uniLeft = 0, uniRight = 0;
    if (root->left && root->left->val == root->val)
        uniLeft = left + 1;
    if (root->right && root->right->val == root->val)
        uniRight = right + 1;
    *ans = max(*ans, uniLeft + uniRight);
    return max(uniLeft, uniRight);
}

int longestUnivaluePath(struct TreeNode *root)
{
    int ans = 0;
    helper(root, &ans);
    return ans;
}
