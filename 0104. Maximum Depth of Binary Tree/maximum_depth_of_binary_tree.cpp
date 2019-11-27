#include <algorithm>
#include <queue>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    int maxDepth_MK1(TreeNode *root);   // Recursive, DFS
    int maxDepth_MK2(TreeNode *root);   // Iterative, BFS
};

// Recursive, DFS
int Solution::maxDepth_MK1(TreeNode *root)
{
    if (!root)
        return 0;
    else
        return 1 + max(maxDepth_MK1(root->left), maxDepth_MK1(root->right));
}

// Iterative, BFS
int Solution::maxDepth_MK2(TreeNode *root)
{
    queue<TreeNode*> que;
    if (root)
        que.push(root);
    int cnt = 0;
    TreeNode *p = nullptr;
    while (!que.empty()) {
        cnt++;
        for (size_t i = 0, size = que.size(); i != size; i++) {
            p = que.front();
            que.pop();
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
    }
    return cnt;
}
