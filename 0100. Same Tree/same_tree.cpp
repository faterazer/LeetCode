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
    bool isSameTree_MK1(TreeNode *p, TreeNode *q);  // Recursion
    bool isSameTree_MK2(TreeNode *p, TreeNode *q);  // Iteration
private:
    bool check(TreeNode *p, TreeNode *q);
};

// Recursion
bool Solution::isSameTree_MK1(TreeNode *p, TreeNode *q)
{
    if (p and q and p->val == q->val)
        return isSameTree_MK1(p->left, q->left) and isSameTree_MK1(p->right, q->right);
    else if (!p and !q)
        return true;
    else
        return false;
}

// Iteration
bool Solution::isSameTree_MK2(TreeNode *p, TreeNode *q)
{
    queue<TreeNode*> p_que, q_que;
    p_que.push(p);
    q_que.push(q);
    while (!p_que.empty() or !q_que.empty()) {
        TreeNode *tp = p_que.front();
        TreeNode *tq = q_que.front();
        p_que.pop();
        q_que.pop();
        if (!check(tp, tq))
            return false;
        if (tp) {
            p_que.push(tp->left);
            p_que.push(tp->right);
            q_que.push(tq->left);
            q_que.push(tq->right);
        }
    }
    return true;
}

bool Solution::check(TreeNode *p, TreeNode *q)
{
    if (p and q and p->val == q->val)
        return true;
    else if (!p and !q)
        return true;
    else
        return false;
}
