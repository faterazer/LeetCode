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
    TreeNode *invertTree_MK1(TreeNode *root);   // Recursive
    TreeNode *invertTree_MK2(TreeNode *root);   // Iterative
};

// Recursive
TreeNode *Solution::invertTree_MK1(TreeNode *root)
{
    if (!root)
        return nullptr;
    swap(root->left, root->right);
    invertTree_MK1(root->left);
    invertTree_MK1(root->right);
    return root;
}

// Iterative
TreeNode* Solution::invertTree_MK2(TreeNode *root)
{
    if (!root)
        return nullptr;
    
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        TreeNode *t = Q.front();
        Q.pop();
        swap(t->left, t->right);
        if (t->left)
            Q.push(t->left);
        if (t->right)
            Q.push(t->right);
    }
    return root;
}
