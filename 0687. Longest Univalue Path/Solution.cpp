#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int longestUnivaluePath(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
private:
    int helper(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        int uniLeft = 0, uniRight = 0;
        if (root->left && root->left->val == root->val)
            uniLeft = left + 1;
        if (root->right && root->right->val == root->val)
            uniRight = right + 1;
        ans = max(ans, uniLeft + uniRight);
        return max(uniLeft, uniRight);
    }
};
