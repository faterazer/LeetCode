#include <stddef.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int getLength(struct ListNode* head)
{
    int res = 0;
    while (head) {
        head = head->next;
        ++res;
    }
    return res;
}

struct TreeNode* buildTree(struct ListNode** head, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = left + ((right - left) >> 1);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = buildTree(head, left, mid - 1);
    root->val = (*head)->val;
    *head = (*head)->next;
    root->right = buildTree(head, mid + 1, right);
    return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head)
{
    int n = getLength(head);
    return buildTree(&head, 0, n - 1);
}
