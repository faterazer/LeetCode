#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int nextLeaf(struct TreeNode *stack[], int *sp)
{
    while (sp > 0) {
        struct TreeNode *p = stack[--(*sp)];
        if (p->right)
            stack[(*sp)++] = p->right;
        if (p->left)
            stack[(*sp)++] = p->left;
        if (!p->left && !p->right)
            return p->val;
    }
    return -1;
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
    struct TreeNode *stack1[256], *stack2[256];
    int sp1 = 0, sp2 = 0;
    stack1[sp1++] = root1;
    stack2[sp2++] = root2;
    while (sp1 > 0 && sp2 > 0)
        if (nextLeaf(stack1, &sp1) != nextLeaf(stack2, &sp2))
            return false;
    return !sp1 && !sp2;
}
