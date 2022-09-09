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
    /**
     * Iterating method using Stack
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    vector<int> inorderTraversal_MK1(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            root = root->right;
        }
        return res;
    }

    /**
     * Morris Traversal
     * Time complexity: O(n)
     * Space complexity: O(1)
     */
    vector<int> inorderTraversal_MK2(TreeNode* root)
    {
        vector<int> res;
        while (root) {
            if (root->left) {
                TreeNode* p = getSuccessor(root);
                if (p->right == root) {
                    p->right = nullptr;
                    res.emplace_back(root->val);
                    root = root->right;
                } else {
                    p->right = root;
                    root = root->left;
                }
            } else {
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }

private:
    TreeNode* getSuccessor(TreeNode* root)
    {
        TreeNode* p = root->left;
        while (p->right && p->right != root)
            p = p->right;
        return p;
    }
};
