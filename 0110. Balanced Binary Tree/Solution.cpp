#include <algorithm>
#include <unordered_map>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution
{
public:
    bool isBalanced(TreeNode *root);
private:
    int depth(TreeNode *root);
};

bool Solution::isBalanced(TreeNode *root)
{
    return depth(root) != -1;
}

int Solution::depth(TreeNode *root)
{
    /*
    如果以 root 为根的树是平衡树，则返回树的深度，否则返回 -1，代表树不平衡
    Return a non-negative value as the tree height, if the substree of the root node is balanced. Otherwise, -1 is returned.
    */
    if (!root)
        return 0;

    int left = depth(root->left);
    int right = depth(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1)
        return -1;
    return max(left, right) + 1;
}
