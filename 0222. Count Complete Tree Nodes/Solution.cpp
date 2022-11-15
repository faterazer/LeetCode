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
    int countNodes(TreeNode* root)
    {
        int lh = leftHeight(root), rh = rightHeight(root);
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

private:
    int leftHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        return 1 + leftHeight(root->left);
    }

    int rightHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        return 1 + rightHeight(root->right);
    }
};
