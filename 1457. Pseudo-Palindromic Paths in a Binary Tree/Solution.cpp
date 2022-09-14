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
    int pseudoPalindromicPaths(TreeNode* root, int cnt = 0)
    {
        if (!root)
            return 0;
        cnt ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, cnt) + pseudoPalindromicPaths(root->right, cnt);
        if (!root->left && !root->right && (cnt & (cnt - 1)) == 0)
            ++res;
        return res;
    }
};
