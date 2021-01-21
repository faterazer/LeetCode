#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<TreeNode*> Q;
        Q.emplace(root);
        while (!Q.empty()) {
            int n = Q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *p = Q.front(); Q.pop();
                if (p->val == x)
                    x = 0;
                else if (p->val == y)
                    y = 0;
                if (p->left && p->right && ((p->left->val == x && p->right->val == y) || (p->left->val == y && p->right->val == x)))
                    return false;
                if (p->left)
                    Q.emplace(p->left);
                if (p->right)
                    Q.emplace(p->right);
            }
            if (!x && !y)
                return true;
            else if (!x || !y)
                return false;
        }
        return false;
    }
};
