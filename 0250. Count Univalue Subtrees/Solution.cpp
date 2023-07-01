// Definition for a binary tree node.
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
    int countUnivalSubtrees(TreeNode* root)
    {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    bool dfs(TreeNode* root, int& res)
    {
        if (!root)
            return true;
        bool lflag = dfs(root->left, res), rflag = dfs(root->right, res);
        if (lflag && rflag) {
            if (root->left && root->left->val != root->val)
                return false;
            if (root->right && root->right->val != root->val)
                return false;
            res++;
            return true;
        }
        return false;
    }
};
