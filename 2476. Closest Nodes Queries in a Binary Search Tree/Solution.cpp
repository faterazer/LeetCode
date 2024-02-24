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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries)
    {
        vector<int> tree;
        inorder(root, tree);

        vector<vector<int>> res;
        for (int query : queries) {
            int i = lower_bound(tree.begin(), tree.end(), query) - tree.begin();
            int max_val = i < tree.size() ? tree[i] : -1;
            if (i == tree.size() || tree[i] != query)
                i--;
            int min_val = i >= 0 ? tree[i] : -1;
            res.push_back({ min_val, max_val });
        }
        return res;
    }

private:
    void inorder(TreeNode* root, vector<int>& tree)
    {
        if (!root)
            return;
        inorder(root->left, tree);
        tree.emplace_back(root->val);
        inorder(root->right, tree);
    }
};
