#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    /**
     * Recursive Preorder Traversal.
     * Time complexity: O(N). N is a number of nodes.
     * Space complexity: O(H). H is a tree height.
     */
    int sumRootToLeaf_MK1(TreeNode *root) { return dfs(root, 0); }

    /**
     * Iterative Preorder Traversal.
     * Time complexity: O(N). N is a number of nodes.
     * Space complexity: O(H). H is a tree height.
     */
    int sumRootToLeaf_MK2(TreeNode *root)
    {
        if (!root)
            return 0;
        stack<pair<TreeNode *, int>> stk;
        stk.emplace(make_pair(root, 0));
        int ret = 0;
        while (!stk.empty())
        {
            auto [p, cur] = stk.top();
            stk.pop();
            cur = (cur << 1) + p->val;
            if (!p->left && !p->right)
                ret += cur;
            else
            {
                if (p->right)
                    stk.emplace(make_pair(p->right, cur));
                if (p->left)
                    stk.emplace(make_pair(p->left, cur));
            }
        }
        return ret;
    }

    /**
     * Morris Preorder Traversal.
     * Time complexity: O(N). N is a number of nodes.
     * Space complexity: O(1).
     */
    int sumRootToLeaf_MK3(TreeNode *root)
    {
        int ret = 0, cur = 0, steps = 0;
        while (root)
        {
            if (!root->left)
            {
                cur = (cur << 1) + root->val;
                root = root->right;
                if (!root)
                    ret += cur;
            }
            else
            {
                TreeNode *succ = root->left;
                steps = 1;
                while (succ->right && succ->right != root)
                {
                    succ = succ->right;
                    steps += 1;
                }
                if (succ->right == nullptr)
                {
                    cur = (cur << 1) + root->val;
                    succ->right = root;
                    root = root->left;
                }
                else
                {
                    succ->right = nullptr;
                    if (!succ->left)
                        ret += cur;
                    for (int i = 0; i < steps; i++)
                        cur >>= 1;
                    root = root->right;
                }
            }
        }
        return ret;
    }

private:
    int dfs(TreeNode *root, int cur)
    {
        if (!root)
            return 0;
        cur = (cur << 1) + root->val;
        return !root->left && !root->right
                   ? cur
                   : dfs(root->left, cur) + dfs(root->right, cur);
    }
};
