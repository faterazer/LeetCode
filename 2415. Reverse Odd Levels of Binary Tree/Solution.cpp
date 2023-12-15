#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 **/
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
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        dfs(root->left, root->right, true);
        return root;
    }

private:
    void dfs(TreeNode* root1, TreeNode* root2, bool is_odd)
    {
        if (!root1)
            return;
        if (is_odd)
            swap(root1->val, root2->val);
        dfs(root1->left, root2->right, !is_odd);
        dfs(root1->right, root2->left, !is_odd);
    }
};
