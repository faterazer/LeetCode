struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isUnivalTree(TreeNode *root, TreeNode *pre = nullptr)
    {
        if (!root)
            return true;
        else if (pre && pre->val != root->val)
            return false;
        else
            return isUnivalTree(root->left, root) && isUnivalTree(root->right, root);
    }
};
