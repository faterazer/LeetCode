#include <utility>
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
    TreeNode* lcaDeepestLeaves(TreeNode* root)
    {
        return dfs(root).second;
    }

private:
    pair<int, TreeNode*> dfs(TreeNode* root)
    {
        if (!root)
            return { 0, nullptr };
        pair<int, TreeNode*> left = dfs(root->left);
        pair<int, TreeNode*> right = dfs(root->right);
        if (left.first > right.first)
            return { left.first + 1, left.second };
        else if (left.first < right.first)
            return { right.first + 1, right.second };
        else
            return { left.first + 1, root };
    }
};
