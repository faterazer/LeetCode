#include <functional>
#include <utility>
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
    int amountOfTime(TreeNode* root, int start)
    {
        int res = 0;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node)
                return 0;

            int ldepth = dfs(node->left), rdepth = dfs(node->right);
            if (node->val == start) {
                res = -min(ldepth, rdepth);
                return 1;
            }
            if (ldepth > 0 || rdepth > 0) {
                res = max(res, abs(ldepth) + abs(rdepth));
                return max(ldepth, rdepth) + 1;
            } else
                return min(ldepth, rdepth) - 1;
        };

        dfs(root);
        return res;
    }
};
