#include <climits>
#include <queue>
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
    int maxLevelSum(TreeNode* root)
    {
        int res = -1, max_sum = INT_MIN;
        queue<TreeNode*> Q;
        Q.emplace(root);
        int layer = 0;
        while (!Q.empty()) {
            int size = Q.size(), tmp_sum = 0;
            ++layer;
            for (int i = 0; i < size; ++i) {
                TreeNode* p = Q.front();
                Q.pop();
                tmp_sum += p->val;
                if (p->left)
                    Q.emplace(p->left);
                if (p->right)
                    Q.emplace(p->right);
            }
            if (tmp_sum > max_sum) {
                res = layer;
                max_sum = tmp_sum;
            }
        }
        return res;
    }
};
