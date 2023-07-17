#include <cmath>

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
    int closestValue(TreeNode* root, double target)
    {
        int res = root->val;
        while (root) {
            if (abs(root->val - target) < abs(res - target) || (abs(root->val - target) == abs(res - target) && root->val < res))
                res = root->val;
            root = root->val > target ? root->left : root->right;
        }
        return res;
    }
};
