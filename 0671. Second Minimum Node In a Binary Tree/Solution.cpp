#include <stack>
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
    int findSecondMinimumValue(TreeNode *root)
    {
        int min1 = root->val, min2 = -1;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            TreeNode *p = stk.top();
            stk.pop();
            if (p->val > min1) {
                if (min2 == -1)
                    min2 = p->val;
                else
                    min2 = min(min2, p->val);
            }
            if (p->left) {
                stk.push(p->right);
                stk.push(p->left);
            }
        }
        return min2;
    }
};
