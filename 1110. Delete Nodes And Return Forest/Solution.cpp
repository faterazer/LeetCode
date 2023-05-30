#include <unordered_set>
#include <vector>
using namespace std;

// Definition for a binary tree node.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        unordered_set<int> del_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        dfs(root, del_set, res, true);
        return res;
    }

private:
    TreeNode* dfs(TreeNode* node, const unordered_set<int>& del_set, vector<TreeNode*>& res, bool is_root)
    {
        if (!node)
            return nullptr;
        if (del_set.count(node->val)) {
            dfs(node->left, del_set, res, true);
            dfs(node->right, del_set, res, true);
            delete node;
            return nullptr;
        }
        if (is_root)
            res.emplace_back(node);
        node->left = dfs(node->left, del_set, res, false);
        node->right = dfs(node->right, del_set, res, false);
        return node;
    }
};
