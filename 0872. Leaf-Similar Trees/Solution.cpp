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
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        stack<TreeNode *> s1, s2;
        s1.emplace(root1);
        s2.emplace(root2);
        while (!s1.empty() && !s2.empty())
            if (nextLeaf(s1) != nextLeaf(s2))
                return false;
        return s1.empty() && s2.empty();
    }

private:
    int nextLeaf(stack<TreeNode *> &s)
    {
        while (!s.empty()) {
            TreeNode *p = s.top(); s.pop();
            if (p->right)
                s.emplace(p->right);
            if (p->left)
                s.emplace(p->left);
            if (!p->left && !p->right)
                return p->val;
        }
        return -1;
    }
};
