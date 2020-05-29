struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root);
};

int Solution::sumOfLeftLeaves(TreeNode *root)
{
    if (!root)
        return 0;
    if (root->left && !root->left->left && !root->left->right)
        return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
