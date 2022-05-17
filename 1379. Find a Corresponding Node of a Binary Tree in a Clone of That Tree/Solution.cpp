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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if (!original || original == target)
            return cloned;
        TreeNode *r = getTargetCopy(original->left, cloned->left, target);
        if (r)
            return r;
        return getTargetCopy(original->right, cloned->right, target);
    }
};
