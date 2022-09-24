struct LinkNode {
    LinkNode(int x)
        : val(x)
        , next(nullptr)
    {
    }

    LinkNode(int x, LinkNode* p)
        : val(x)
        , next(p)
    {
    }

    int val;
    LinkNode* next = nullptr;
};

class MyLinkedList {
public:
    MyLinkedList()
    {
    }

    int get(int index)
    {
        if (index < 0 || index >= head->val)
            return -1;

        LinkNode* p = head->next;
        while (index--)
            p = p->next;
        return p->val;
    }

    void addAtHead(int val)
    {
        LinkNode* p = new LinkNode(val, head->next);
        head->next = p;
        ++head->val;
        if (tail == head)
            tail = head->next;
    }

    void addAtTail(int val)
    {
        LinkNode* p = new LinkNode(val, tail->next);
        tail->next = p;
        tail = p;
        ++head->val;
    }

    void addAtIndex(int index, int val)
    {
        if (index > head->val)
            return;

        if (index < 0)
            addAtTail(val);
        else if (index == head->val)
            addAtTail(val);
        else {
            LinkNode* pre = head;
            while (index--)
                pre = pre->next;
            LinkNode* p = new LinkNode(val, pre->next);
            pre->next = p;
            ++head->val;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= head->val)
            return;
        LinkNode* pre = head;
        while (index--)
            pre = pre->next;
        LinkNode* p = pre->next;
        pre->next = p->next;
        if (p == tail)
            tail = pre;
        delete p;
        --head->val;
    }

private:
    LinkNode *head = new LinkNode(0), *tail = head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
