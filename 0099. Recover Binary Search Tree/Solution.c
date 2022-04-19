#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* getPredecessor(struct TreeNode* root)
{
    struct TreeNode* r = root->left;
    while (r->right && r->right != root)
        r = r->right;
    return r;
}

void recoverTree(struct TreeNode* root)
{
    struct TreeNode *a = NULL, *b = NULL, *last = NULL;
    while (root) {
        if (last && last->val > root->val) {
            if (!a)
                a = last;
            b = root;
        }

        if (!root->left) {
            last = root;
            root = root->right;
        } else {
            struct TreeNode* pred = getPredecessor(root);
            if (pred->right == root) {
                pred->right = NULL;
                last = root;
                root = root->right;
            } else {
                pred->right = root;
                root = root->left;
            }
        }
    }
    
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}
