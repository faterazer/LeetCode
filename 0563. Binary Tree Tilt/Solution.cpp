#include <cmath>

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
    int findTilt(TreeNode *root)
    {
        int tilt = 0;
        findTilt(root, tilt);
        return tilt;
    }
private:
    int findTilt(TreeNode *root, int &tilt)
    {
        if (!root)
            return 0;
        int left = findTilt(root->left, tilt);
        int right = findTilt(root->right, tilt);
        tilt += abs(left - right);
        return root->val + left + right;
    }
};
