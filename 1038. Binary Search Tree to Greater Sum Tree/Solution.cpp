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
    /**
     * Recursion 递归
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    TreeNode* bstToGst_MK1(TreeNode *root)
    {
        int preSum = 0;
        inOrder(root, preSum);
        return root;
    }

    /**
     * Iteration with a Stack 迭代
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    TreeNode* bstToGst_MK2(TreeNode *root)
    {
        stack<TreeNode*> stk;
        TreeNode *p = root;
        int preSum = 0;
        while (stk.size() || p) {
            while (p) {
                stk.emplace(p);
                p = p->right;
            }
            p = stk.top();
            stk.pop();
            p->val += preSum;
            preSum = p->val;
            p = p->left;
        }
        return root;
    }

    /**
     * Reverse Morris In-order Traversal 反转中序 Morris 遍历
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    TreeNode* bstToGst_MK3(TreeNode *root)
    {
        int preSum = 0;
        TreeNode *p = root;
        while (p) {
            if (!p->right) {
                p->val += preSum;
                preSum = p->val;
                p = p->left;
            }
            else {
                TreeNode *succ = getSuccessor(p);
                if (!succ->left) {
                    succ->left = p;
                    p = p->right;
                }
                else {
                    succ->left = nullptr;
                    p->val += preSum;
                    preSum = p->val;
                    p = p->left;
                }
            }
        }
        return root;
    }
private:
    void inOrder(TreeNode *root, int &preSum)
    {
        if (!root)
            return;
        inOrder(root->right, preSum);
        root->val += preSum;
        preSum = root->val;
        inOrder(root->left, preSum);
    }

    TreeNode* getSuccessor(TreeNode *root)
    {
        TreeNode *succ = root->right;
        while (succ->left && succ->left != root)
            succ = succ->left;
        return succ;
    }
};
