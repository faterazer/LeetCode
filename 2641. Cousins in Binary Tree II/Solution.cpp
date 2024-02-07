#include <queue>
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
    TreeNode* replaceValueInTree(TreeNode* root)
    {
        queue<TreeNode*> Q;
        Q.emplace(root);
        root->val = 0;
        while (!Q.empty()) {
            int row_sum = 0, n = Q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* p = Q.front();
                Q.pop();
                row_sum += (p->left ? p->left->val : 0) + (p->right ? p->right->val : 0);
                Q.emplace(p);
            }
            for (int i = 0; i < n; i++) {
                TreeNode* p = Q.front();
                Q.pop();
                int children_sum = (p->left ? p->left->val : 0) + (p->right ? p->right->val : 0);
                if (p->left) {
                    p->left->val = row_sum - children_sum;
                    Q.emplace(p->left);
                }
                if (p->right) {
                    p->right->val = row_sum - children_sum;
                    Q.emplace(p->right);
                }
            }
        }
        return root;
    }
};
