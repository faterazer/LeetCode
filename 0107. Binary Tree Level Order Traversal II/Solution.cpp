#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ret_vec;
        if (!root)
            return ret_vec;

        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *t = nullptr;
            vector<int> tmp_vec;
            for (size_t i = 0, n = que.size(); i != n; i++) {
                t = que.front();
                que.pop();
                tmp_vec.emplace_back(t->val);
                if (t->left)
                    que.push(t->left);
                if (t->right)
                    que.push(t->right);
            }
            ret_vec.push_back(tmp_vec);
        }
        reverse(ret_vec.begin(), ret_vec.end());
        return ret_vec;
    }
};
