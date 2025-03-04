#include <functional>
#include <string>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

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
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if (!root)
            return false;

        function<bool(TreeNode*, ListNode*)> dfs = [&](TreeNode* t, ListNode* h) -> bool {
            if (!h)
                return true;
            if (!t)
                return false;
            if (t->val != h->val)
                return false;
            return dfs(t->left, h->next) || dfs(t->right, h->next);
        };

        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
