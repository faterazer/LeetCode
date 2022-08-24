#include <cmath>
#include <string>
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
    vector<vector<string>> printTree(TreeNode* root)
    {
        int h = depth(root);
        int m = h, n = pow(2, h) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        helper(root, 0, n - 1, res, 0);
        return res;
    }

private:
    int depth(TreeNode* root)
    {
        if (!root)
            return 0;
        int l = depth(root->left), r = depth(root->right);
        return max(l, r) + 1;
    }

    void helper(TreeNode* root, int l, int r, vector<vector<string>>& res, int d)
    {
        if (!root || l > r)
            return;
        int m = l + ((r - l) >> 1);
        res[d][m] = to_string(root->val);
        helper(root->left, l, m - 1, res, d + 1);
        helper(root->right, m + 1, r, res, d + 1);
    }
};
