#include <algorithm>
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
    void recoverTree(TreeNode* root)
    {
        TreeNode *a = nullptr, *b = nullptr, *last = nullptr;
        while (root) {
            if (last && last->val > root->val) {
                if (!a)
                    a = last;
                b = root;
            }

            if (!root->left) {
                last = root;
                root = root->right;
            } else {
                TreeNode* pred = getPredecessor(root);
                if (pred->right == root) {
                    pred->right = nullptr;
                    last = root;
                    root = root->right;
                } else {
                    pred->right = root;
                    root = root->left;
                }
            }
        }
        swap(a->val, b->val);
    }

private:
    TreeNode* getPredecessor(TreeNode* root)
    {
        TreeNode* r = root->left;
        while (r->right && r->right != root)
            r = r->right;
        return r;
    }
};
