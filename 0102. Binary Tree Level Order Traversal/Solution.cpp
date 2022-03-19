#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<TreeNode*> Q;
        Q.emplace(root);
        while (!Q.empty()) {
            int n = Q.size();
            vector<int> layer;
            layer.reserve(n);
            for (int i = 0; i < n; ++i) {
                TreeNode* node = Q.front();
                Q.pop();
                layer.emplace_back(node->val);
                if (node->left)
                    Q.emplace(node->left);
                if (node->right)
                    Q.emplace(node->right);
            }
            res.emplace_back(layer);
        }
        return res;
    }
};
