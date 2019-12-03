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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return sortedArrayToBSTNode(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* sortedArrayToBSTNode(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTNode(nums, left, mid - 1);
        root->right = sortedArrayToBSTNode(nums, mid + 1, right);
        return root;
    }
};
