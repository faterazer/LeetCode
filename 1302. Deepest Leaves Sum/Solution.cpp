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
    int deepestLeavesSum(TreeNode* root)
    {
        int max_depth = -1;
        int res = 0;
        dfs(root, 0, max_depth, res);
        return res;
    }

private:
    void dfs(TreeNode *root, int depth, int &max_depth, int &res)
    {
        if (!root)
            return;
        if (depth > max_depth) {
            max_depth = depth;
            res = root->val;
        } else if (depth == max_depth)
            res += root->val;
        dfs(root->left, depth + 1, max_depth, res);
        dfs(root->right, depth + 1, max_depth, res);
    }
};
