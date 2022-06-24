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
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* root, int depth, vector<int>& res)
    {
        if (!root)
            return;
        if (depth >= res.size())
            res.emplace_back(root->val);
        else
            res[depth] = max(res[depth], root->val);
        dfs(root->left, depth + 1, res);
        dfs(root->right, depth + 1, res);
    }
};
