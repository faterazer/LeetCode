#include <vector>
using namespace std;

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if (!root)
            return res;
        vector<int> path;
        dfs(root, targetSum, path);
        return res;
    }

private:
    void dfs(TreeNode* root, int targetSum, vector<int> & path)
    {
        if (!root)
            return;
        targetSum -= root->val;
        path.emplace_back(root->val);
        if (!targetSum && !root->left && !root->right)
            res.emplace_back(path);
        dfs(root->left, targetSum, path);
        dfs(root->right, targetSum, path);
        path.pop_back();
    }

    vector<vector<int>> res;
};
