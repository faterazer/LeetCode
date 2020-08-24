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
    bool isSubtree_MK1(TreeNode *s, TreeNode *t)
    {
        if (!s)
            return false;
        else
            return isSame(s, t) || isSubtree_MK1(s->left, t) || isSubtree_MK1(s->right, t);
    }

    bool isSubtree_MK2(TreeNode *s, TreeNode *t)
    {
        string ss = preOrder(s);
        string ts = preOrder(t);
        return ss.find(ts) != ss.npos;
    }

private:
    bool isSame(TreeNode *s, TreeNode *t)
    {
        if (!s && !t)
            return true;
        else if (!s || !t || s->val != t->val)
            return false;
        else
            return isSame(s->left, t->left) && isSame(s->right, t->right);
    }

    string preOrder(TreeNode *root)
    {
        if (!root)
            return "null";
        return "#" + to_string(root->val) + preOrder(root->left) + preOrder(root->right);
    }
};
