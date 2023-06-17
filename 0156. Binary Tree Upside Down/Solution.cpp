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
    TreeNode* upsideDownBinaryTree(TreeNode* root)
    {
        if (!root || !root->left)
            return root;
        TreeNode *lchild = root->left, *rchild = root->right;
        TreeNode* res = upsideDownBinaryTree(root->left);
        root->left = root->right = nullptr;
        lchild->left = rchild;
        lchild->right = root;
        return res;
    }
};
