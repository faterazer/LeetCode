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
    vector<int> rightSideView(TreeNode *root);
};

vector<int> Solution::rightSideView(TreeNode *root)
{
    vector<int> ret;
    if (!root)
        return ret;
        
    queue<TreeNode*> Q;
    Q.emplace(root);
    while (!Q.empty()) {
        int n = Q.size();
        TreeNode *t = nullptr;
        for (int i = 0; i < n; i++) {
            t = Q.front();
            Q.pop();
            if (t->left)
                Q.emplace(t->left);
            if (t->right)
                Q.emplace(t->right);
        }
        ret.emplace_back(t->val);
    }
    return ret;
}
