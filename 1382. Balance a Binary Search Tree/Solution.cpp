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
    TreeNode* balanceBST(TreeNode* root)
    {
        vector<int> buffer;

        auto in_order = [&](this auto&& self, TreeNode* node) -> void {
            if (node->left)
                self(node->left);
            buffer.push_back(node->val);
            if (node->right)
                self(node->right);
        };

        in_order(root);

        auto build_BST = [&](this auto&& self, int lo, int hi) -> TreeNode* {
            if (lo > hi)
                return nullptr;
            int mid = lo + ((hi - lo) >> 1);
            TreeNode* node = new TreeNode(buffer[mid]);
            node->left = self(lo, mid - 1);
            node->right = self(mid + 1, hi);
            return node;
        };

        return build_BST(0, buffer.size() - 1);
    }
};
