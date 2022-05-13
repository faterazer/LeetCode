struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node* connect(struct Node* root)
{
    if (!root)
        return root;
    struct Node* leftmost = root;
    while (leftmost->left) {
        struct Node* head = leftmost;
        while (head) {
            head->left->next = head->right;
            if (head->next)
                head->right->next = head->next->left;
            head = head->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}
