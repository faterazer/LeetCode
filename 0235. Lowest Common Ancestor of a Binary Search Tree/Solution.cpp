#include <vector>
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
    TreeNode* lowestCommonAncestor_MK1(TreeNode *root, TreeNode *p, TreeNode *q); // Recursive
    TreeNode* lowestCommonAncestor_MK2(TreeNode *root, TreeNode *p, TreeNode *q); // Iterative
};

// Recursive
TreeNode *Solution::lowestCommonAncestor_MK1(TreeNode *root, TreeNode *p, TreeNode *q)
{
    int smaller = min(p->val, q->val);
    int bigger = max(p->val, q->val);
    if (root->val >= smaller && root->val <= bigger)
        return root;
    return bigger < root->val ? lowestCommonAncestor_MK1(root->left, p, q) : lowestCommonAncestor_MK1(root->right, p, q);
}

// Iterative
TreeNode* Solution::lowestCommonAncestor_MK2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *curr = root;
    int pval = p->val, qval = q->val;
    while (curr) {
        if (pval < curr->val && qval < curr->val)
            curr = curr->left;
        else if (pval > curr->val && qval > curr->val)
            curr = curr->right;
        else
            return curr;
    }
    return nullptr;
}
