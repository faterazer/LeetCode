#include <unordered_map>
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
    int pathSum(TreeNode *root, int sum);
private:
    int pathSum(TreeNode *root, const int &target, unordered_map<int, int> &path, int pre_sum);
};

int Solution::pathSum(TreeNode *root, int sum)
{
    unordered_map<int,int> path;
    path[0] = 1;
    return pathSum(root, sum, path, 0);
}

int Solution::pathSum(TreeNode *root, const int &target, unordered_map<int, int> &path, int pre_sum)
{
    if (!root)
        return 0;
    
    pre_sum += root->val;
    int res = 0;
    if (path.find(pre_sum - target) != path.end())
        res += path[pre_sum - target];
    path[pre_sum]++;
    res += pathSum(root->left, target, path, pre_sum) + pathSum(root->right, target, path, pre_sum);
    path[pre_sum]--;
    return res;
}
