#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& inorder, int l, int r, vector<int>& postorder, int idx)
    {
        if (l > r || idx < 0)
            return nullptr;

        TreeNode* root = new TreeNode(postorder[idx]);
        int m = find(inorder.begin() + l, inorder.begin() + r + 1, postorder[idx]) - inorder.begin();
        root->left = buildTree(inorder, l, m - 1, postorder, idx - (r - m + 1));
        root->right = buildTree(inorder, m + 1, r, postorder, idx - 1);
        return root;
    }
};
