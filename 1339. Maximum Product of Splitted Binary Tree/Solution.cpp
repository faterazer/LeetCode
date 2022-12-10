#include <algorithm>
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
    int maxProduct(TreeNode* root)
    {
        int P = 1e9 + 7;
        int sum = treeSum(root);
        int res = 0;
        helper(root, sum, res);
        return static_cast<long long>(res) * (sum - res) % P;
    }

private:
    int treeSum(TreeNode* root)
    {
        if (!root)
            return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }

    int helper(TreeNode* root, int sum, int& res)
    {
        if (!root)
            return 0;
        int cur = root->val + helper(root->left, sum, res) + helper(root->right, sum, res);
        if (abs(cur * 2 - sum) < abs(res * 2 - sum))
            res = cur;
        return cur;
    }
};
