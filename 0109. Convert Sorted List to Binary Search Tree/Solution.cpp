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
    TreeNode* sortedListToBST(ListNode* head)
    {
        int len = getLength(head);
        return buildTree(head, 0, len - 1);
    }

private:
    int getLength(ListNode* head)
    {
        int res = 0;
        while (head) {
            ++res;
            head = head->next;
        }
        return res;
    }

    TreeNode* buildTree(ListNode*& head, int left, int right)
    {
        if (left > right)
            return nullptr;
        int mid = left + ((right - left) >> 1);
        TreeNode* root = new TreeNode();
        root->left = buildTree(head, left, mid - 1);
        root->val = head->val;
        head = head->next;
        root->right = buildTree(head, mid + 1, right);
        return root;
    }
};
