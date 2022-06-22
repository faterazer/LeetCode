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
    int findBottomLeftValue(TreeNode* root)
    {
        int max_depth = -1, res = root->val;
        dfs(root, 0, res, max_depth);
        return res;
    }

private:
    void dfs(TreeNode *root, int depth, int &res, int &max_depth) {
        if (!root)
            return;
        if (depth > max_depth) {
            max_depth = depth;
            res = root->val;
        }
        dfs(root->left, depth + 1, res, max_depth);
        dfs(root->right, depth + 1, res, max_depth);
    }
};
