class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node()
        : val(0)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr)
    {
    }

    Node(int _val)
        : val(_val)
        , left(nullptr)
        , right(nullptr)
        , next(nullptr)
    {
    }

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val)
        , left(_left)
        , right(_right)
        , next(_next)
    {
    }
};

class Solution {
public:
    Node* connect_MK1(Node* root, Node* next_ptr = nullptr)
    {
        if (!root)
            return nullptr;
        root->next = next_ptr;
        connect_MK1(root->left, root->right);
        if (next_ptr) {
            connect_MK1(root->right, next_ptr->left);
            connect_MK1(next_ptr->left, next_ptr->right);
        }
        return root;
    }

    Node* connect_MK2(Node* root, Node* next_ptr = nullptr)
    {
        if (!root)
            return nullptr;
        Node *leftmost = root;
        while (leftmost->left) {
            Node *head = leftmost;
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
};
