#include <algorithm>
#include <queue>
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
    int minDepth_MK1(TreeNode *root);   // DFS
    int minDepth_MK2(TreeNode *root);   // BFS
};

// DFS
int Solution::minDepth_MK1(TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->left)
        return minDepth_MK1(root->right) + 1;
    if (!root->right)
        return minDepth_MK1(root->left) + 1;
    return min(minDepth_MK1(root->left), minDepth_MK1(root->right)) + 1;
}

// BFS
int Solution::minDepth_MK2(TreeNode *root)
{
    if (!root)
        return 0;

    queue<TreeNode*> que;
    que.push(root);
    int depth = 0;
    while (!que.empty()) {
        depth++;
        for (size_t i = 0, n = que.size(); i != n; i++) {
            TreeNode *t = que.front();
            que.pop();
            if (!t->left && !t->right)
                return depth;
            if (t->left)
                que.push(t->left);
            if (t->right)
                que.push(t->right);
        }
    }
    return depth;
}
