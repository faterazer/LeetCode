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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
    {
        return buildTree(preorder, 0, preorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int l1, int r1, vector<int>& postorder, int l2, int r2)
    {
        if (l1 > r1 || l2 > r2)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[l1]);
        if (l1 == r1)
            return root;
        l1++;
        r2--;

        int m = find(postorder.begin() + l2, postorder.begin() + r2 + 1, preorder[l1]) - postorder.begin();
        root->left = buildTree(preorder, l1, l1 + m - l2, postorder, l2, m);
        root->right = buildTree(preorder, l1 + m - l2 + 1, r1, postorder, m + 1, r2);
        return root;
    }
};
