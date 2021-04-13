#include <limits.h>
#include <math.h>

#define min(a, b) ((a < b) ? (a) : (b))

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inOrder(struct TreeNode *root, struct TreeNode **pre, int *ans);
struct TreeNode* getSuccessor(struct TreeNode *root);

// Recurive
int getMinimumDifference_MK1(struct TreeNode *root)
{
    struct TreeNode *pre = NULL;
    int ans = INT_MAX;
    inOrder(root, &pre, &ans);
    return ans;
}

// Mirrors
int getMinimumDifference_MK2(struct TreeNode *root)
{
    int ans = INT_MAX;
    struct TreeNode *pre = NULL;
    while (root) {
        if (pre)
            ans = min(ans, abs(root->val - pre->val));
        if (!root->left) {
            pre = root;
            root = root->right;
        }
        else {
            struct TreeNode *succ = getSuccessor(root);
            if (!succ->right) {
                succ->right = root;
                root = root->left;
            }
            else {
                succ->right = NULL;
                pre = root;
                root = root->right;
            }
        }
    }
    return ans;
}

void inOrder(struct TreeNode *root, struct TreeNode **pre, int *ans)
{
    if (root->left)
        inOrder(root->left, pre, ans);
    if (*pre)
        *ans = min(*ans, root->val - (*pre)->val);
    *pre = root;
    if (root->right)
        inOrder(root->right, pre, ans);
}

struct TreeNode* getSuccessor(struct TreeNode *root)
{
    struct TreeNode *p = root->left;
    while (p->right && p->right != root)
        p = p->right;
    return p;
}
