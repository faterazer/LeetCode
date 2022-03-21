struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root || root == p || root == q)
            return root;

        TreeNode *lp = lowestCommonAncestor(root->left, p, q);
        TreeNode *rp = lowestCommonAncestor(root->right, p, q);
        if (lp && rp)
            return root;
        else if (lp || rp)
            return lp ? lp : rp;
        else
            return nullptr;
    }
};
