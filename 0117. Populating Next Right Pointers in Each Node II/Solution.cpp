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
    Node* connect(Node* root)
    {
        if (!root)
            return root;
        for (Node* leftmost = root; leftmost;) {
            Node *last = nullptr, *next_leftmost = nullptr;
            for (Node* head = leftmost; head; head = head->next) {
                if (head->left)
                    helper(last, next_leftmost, head->left);
                if (head->right)
                    helper(last, next_leftmost, head->right);
            }
            leftmost = next_leftmost;
        }
        return root;
    }

private:
    void helper(Node*& last, Node*& next_leftmost, Node*& p)
    {
        if (last)
            last->next = p;
        if (!next_leftmost)
            next_leftmost = p;
        last = p;
    }
};
