#include <stack>
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
    vector<int> preorderTraversal_MK1(TreeNode* root) // Recursive
    {
        vector<int> res;
        preorder(root, res);
        return res;
    }

    vector<int> preorderTraversal_MK2(TreeNode* root) // Iterative
    {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            res.emplace_back(p->val);
            if (p->right)
                stk.emplace(p->right);
            if (p->left)
                stk.emplace(p->left);
        }
        return res;
    }

    vector<int> preorderTraversal_MK3(TreeNode* root) // Morris
    {
        vector<int> res;
        TreeNode* cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode* succ = getSuccessor(cur);
                if (succ->right == cur) {
                    succ->right = nullptr;
                    cur = cur->right;
                } else {
                    res.emplace_back(cur->val);
                    succ->right = cur;
                    cur = cur->left;
                }
            } else {
                res.emplace_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }

private:
    void preorder(TreeNode* root, vector<int>& res)
    {
        if (!root)
            return;
        res.emplace_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    TreeNode* getSuccessor(TreeNode* root)
    {
        TreeNode* res = root->left;
        while (res->right && res->right != root)
            res = res->right;
        return res;
    }
};
