#include <algorithm>
#include <utility>
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
    int maxAncestorDiff(TreeNode* root)
    {
        int res = 0;
        helper(root, res);
        return res;
    }

private:
    pair<int, int> helper(TreeNode* root, int& res)
    {
        if (!root)
            return make_pair(INT_MAX, INT_MIN);
        pair<int, int> lminmax = helper(root->left, res);
        pair<int, int> rminmax = helper(root->right, res);
        int min_val = min(root->val, min(lminmax.first, rminmax.first));
        int max_val = max(root->val, max(lminmax.second, rminmax.second));
        res = max(res, max(root->val - min_val, max_val - root->val));
        return make_pair(min_val, max_val);
    }
};
