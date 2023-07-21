#include <set>
#include <vector>
using namespace std;

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
    vector<int> closestKValues(TreeNode* root, double target, int k)
    {
        set<int> res;
        helper(root, target, k, res);
        return vector<int>(res.begin(), res.end());
    }

private:
    void helper(TreeNode* root, double target, int k, set<int>& res)
    {
        if (!root)
            return;
        if (res.size() < k) {
            res.emplace(root->val);
            helper(root->left, target, k, res);
            helper(root->right, target, k, res);
            return;
        }

        double left_margin = abs(static_cast<double>(*res.begin()) - target);
        double right_margin = abs(static_cast<double>(*res.rbegin()) - target);
        double cur_margin = abs(static_cast<double>(root->val) - target);
        if (cur_margin < max(left_margin, right_margin)) {
            if (left_margin < right_margin)
                res.erase(*res.rbegin());
            else
                res.erase(*res.begin());
            res.emplace(root->val);
            helper(root->left, target, k, res);
            helper(root->right, target, k, res);
        } else if (root->val > *res.rbegin())
            helper(root->left, target, k, res);
        else
            helper(root->right, target, k, res);
    }
};
