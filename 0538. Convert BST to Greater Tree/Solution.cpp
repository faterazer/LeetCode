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
     * Recursion approach 递归方法
     * Time complexity: O(n)
     * Space Complexity: O(n)
     */
    TreeNode* convertBST_MK1(TreeNode *root)
    {
        int preSum = 0;
        convertBST(root, preSum);
        return root;
    }

    /**
     * Iteration with a Stack 迭代方法
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    TreeNode* convertBST_MK2(TreeNode *root)
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
    TreeNode* convertBST_MK3(TreeNode *root)
    {
        int sum = 0;
        TreeNode *p = root;
        while (p) {
            if (!p->right) {
                p->val += sum;
                sum = p->val;
                p = p->left;
            }
            else {
                TreeNode *succ = getSuccessor(p);
                if (succ->left) {
                    succ->left = nullptr;
                    p->val += sum;
                    sum = p->val;
                    p = p->left;
                }
                else {
                    succ->left = p;
                    p = p->right;
                }
            }
        }
        return root;
    }
private:
    void convertBST(TreeNode *root, int &preSum)
    {
        if (!root)
            return;
        convertBST(root->right, preSum);
        root->val += preSum;
        preSum = root->val;
        convertBST(root->left, preSum);
    }

    TreeNode* getSuccessor(TreeNode *p)
    {
        TreeNode *succ = p->right;
        while (succ->left && succ->left != p)
            succ = succ->left;
        return succ;
    }
};
