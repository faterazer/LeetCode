#include <algorithm>
#include <stack>
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
    vector<int> postorderTraversal_MK1(TreeNode* root) // 用 stack 迭代
    {
        vector<int> res;
        if (root == nullptr)
            return res;

        stack<TreeNode*> stk;
        stk.emplace(root);
        TreeNode* last_popped = nullptr;
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            if ((p->left == nullptr && p->right == nullptr) || (last_popped && (last_popped == p->left || last_popped == p->right))) {
                res.emplace_back(p->val);
                stk.pop();
                last_popped = p;
            } else {
                if (p->right)
                    stk.emplace(p->right);
                if (p->left)
                    stk.emplace(p->left);
            }
        }
        return res;
    }

    vector<int> postorderTraversal_MK2(TreeNode* root) // Morris
    {
        vector<int> res;
        if (!root)
            return res;

        TreeNode* p = root;
        while (p) {
            if (!p->left)
                p = p->right;
            else {
                TreeNode* succ = getSuccessor(p);
                if (succ->right != p) {
                    succ->right = p;
                    p = p->left;
                } else {
                    succ->right = nullptr;
                    addPath(res, p->left);
                    p = p->right;
                }
            }
        }
        addPath(res, root);
        return res;
    }

private:
    TreeNode* getSuccessor(TreeNode* p)
    {
        TreeNode* succ = p->left;
        while (succ->right && succ->right != p)
            succ = succ->right;
        return succ;
    }

    void addPath(vector<int>& res, TreeNode* node)
    {
        int cnt = 0;
        while (node) {
            ++cnt;
            res.emplace_back(node->val);
            node = node->right;
        }
        reverse(res.end() - cnt, res.end());
    }
};
