#include <stack>
#include <string>
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
    /**
     * Time complexity: O(n).
     * Space complexity: O(n).
     */
    string tree2str(TreeNode *t)
    {
        if (!t)
            return "";
        else if (!t->left && !t->right)
            return to_string(t->val);
        else if (!t->right)
            return to_string(t->val) + "(" + tree2str(t->left) + ")";
        else
            return to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
    }
};
