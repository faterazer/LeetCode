#include <climits>

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
    bool isValidBST(TreeNode* root)
    {
        TreeNode* pre = nullptr;
        return inorder(root, pre);
    }

private:
    bool inorder(TreeNode* root, TreeNode*& pre)
    {
        if (!root)
            return true;
        if (!inorder(root->left, pre))
            return false;
        if (pre && root->val <= pre->val)
            return false;
        pre = root;
        return inorder(root->right, pre);
    }
};
