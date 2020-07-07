#include <stack>
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
    bool hasPathSum_MK1(TreeNode *root, int sum);   // Recursive
    bool hasPathSum_MK2(TreeNode *root, int sum);   // Iterative
};

// Recursive
bool Solution::hasPathSum_MK1(TreeNode *root, int sum)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
        return root->val == sum;
    sum -= root->val;
    return hasPathSum_MK1(root->left, sum) || hasPathSum_MK1(root->right, sum);
}

// Iterative
bool Solution::hasPathSum_MK2(TreeNode *root, int sum)
{
    if (!root)
        return false;
    stack<TreeNode*> node_stk;
    stack<int> sum_stk;
    node_stk.push(root);
    sum_stk.push(root->val);
    while (!node_stk.empty()) {
        TreeNode *t = node_stk.top();
        node_stk.pop();
        int curr_sum = sum_stk.top();
        sum_stk.pop();
        if (!t->left && !t->right && curr_sum == sum)
            return true;;
        if (t->right) {
            node_stk.push(t->right);
            sum_stk.push(curr_sum + t->right->val);
        }
        if (t->left) {
            node_stk.push(t->left);
            sum_stk.push(curr_sum + t->left->val);
        }
    }
    return false;
}
