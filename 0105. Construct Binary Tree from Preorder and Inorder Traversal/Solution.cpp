#include <algorithm>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTree(preorder, 0, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int> &preorder, int idx, vector<int> &inorder, int l, int r)
    {
        if (idx < 0 || idx >= preorder.size() || l > r)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[idx]);
        int m = find(inorder.begin() + l, inorder.begin() + r + 1, preorder[idx]) - inorder.begin();
        root->left = buildTree(preorder, idx + 1, inorder, l, m - 1);
        root->right = buildTree(preorder, idx + m - l + 1, inorder, m + 1, r);
        return root;
    }
};
