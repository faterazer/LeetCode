struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
    if (p->val > q->val)
        return lowestCommonAncestor(root, q, p);
    if (p->val <= root->val && q->val >= root->val)
        return root;
    else if (q->val <= root->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return lowestCommonAncestor(root->right, p, q);
}
