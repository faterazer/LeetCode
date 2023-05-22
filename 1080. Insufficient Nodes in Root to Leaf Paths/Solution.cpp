struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit)
    {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
            return root->val < limit ? nullptr : root;
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);
        return !root->left && !root->right ? nullptr : root;
    }
};
