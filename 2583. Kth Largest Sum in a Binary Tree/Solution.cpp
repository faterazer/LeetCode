#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        priority_queue<long long, vector<long long>, greater<long long>> min_heap;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int size = Q.size();
            long long level_sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                level_sum += node->val;
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            min_heap.emplace(level_sum);
            if (min_heap.size() > k)
                min_heap.pop();
        }
        return min_heap.size() == k ? min_heap.top() : -1;
    }
};
