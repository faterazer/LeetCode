#include <algorithm>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode*> Q;
        Q.emplace(root);
        while (!Q.empty()) {
            int n = Q.size();
            vector<int> row;
            for (int i = 0; i < n; i++) {
                TreeNode* p = Q.front();
                Q.pop();
                row.emplace_back(p->val);
                if (p->left)
                    Q.emplace(p->left);
                if (p->right)
                    Q.emplace(p->right);
            }
            res.emplace_back(row);
        }
        for (size_t i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};
