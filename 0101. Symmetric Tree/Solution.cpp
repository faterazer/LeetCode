#include <iostream>
#include <queue>
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
    bool isSymmetric_MK1(TreeNode *root);   // Recursive
    bool isSymmetric_MK2(TreeNode *root);   // Iterative
private:
    bool isSymmetric(TreeNode *r1, TreeNode *r2);
};

// Recursive
bool Solution::isSymmetric_MK1(TreeNode *root)
{
    if (!root)
        return true;
    return isSymmetric(root->left, root->right);
}

bool Solution::isSymmetric(TreeNode *r1, TreeNode *r2)
{
    if (!r1 and !r2)
        return true;
    else if (!r1 or !r2)
        return false;
    else
        return r1->val == r2->val and isSymmetric(r1->left, r2->right) and isSymmetric(r1->right, r2->left);
}

bool Solution::isSymmetric_MK2(TreeNode *root)
{
    if (!root)
        return true;
        
    queue<TreeNode*> que;
    que.push(root->left);
    que.push(root->right);
    while (!que.empty()) {
        TreeNode *t1 = que.front();
        que.pop();
        TreeNode *t2 = que.front();
        que.pop();
        if (!t1 and !t2)
            continue;
        else if (!t1 or !t2)
            return false;
        else if (t1->val != t2->val)
            return false;
        que.push(t1->left);
        que.push(t2->right);
        que.push(t1->right);
        que.push(t2->left);
    }
    return true;
}
