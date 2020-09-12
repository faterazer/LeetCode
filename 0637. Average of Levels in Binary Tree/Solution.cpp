#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode*> Q;
        Q.emplace(root);
        vector<double> ret;
        while (!Q.empty()) {
            int n = Q.size();
            double sum = 0.0;
            for (int i = 0; i < n; i++) {
                TreeNode *p = Q.front();
                Q.pop();
                sum += p->val;
                if (p->left)
                    Q.emplace(p->left);
                if (p->right)
                    Q.emplace(p->right);
            }
            ret.emplace_back(sum / n);
        }
        return ret;
    }
};
