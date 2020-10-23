#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool isPalindrome_MK1(ListNode *head);
    bool isPalindrome_MK2(ListNode *head);
};

// Time complexity: O(n)
// Space complexity: O(n)
bool Solution::isPalindrome_MK1(ListNode *head)
{
    vector<int> vi;
    while (head) {
        vi.emplace_back(head->val);
        head = head->next;
    }
    int front = 0, back = vi.size() - 1;
    while (front < back) {
        if (vi[front] != vi[back])
            return false;
        front++;
        back--;
    }
    return true;
}

// Time complexity: O(n)
// Space complexity: O(1)
bool Solution::isPalindrome_MK2(ListNode *head)
{
    // 快慢指针法，拿到后半部分结点的同时，反转前半部分结点
    ListNode *slow = head, *fast = head;
    ListNode *tp = nullptr, *new_head = new ListNode(0);
    while (fast && fast->next) {
        tp = slow;
        slow = slow->next;
        fast = fast->next->next;
        tp->next = new_head->next;
        new_head->next = tp;
    }

    // 后面恢复原链表时用
    tp = slow;

    // 处理长度为奇数的情况
    if (fast)
        slow = slow->next;
    
    // 判断 h1、h2 的元素是否相同
    ListNode *h1 = new_head->next, *h2 = slow;
    while (h1 && h2) {
        if (h1->val != h2->val)
            return false;
        h1 = h1->next;
        h2 = h2->next;
    }

    // 恢复原链表
    ListNode *p = new_head->next, *t = nullptr;
    new_head->next = tp;
    while (p) {
        t = p;
        p = p->next;
        t->next = new_head->next;
        new_head->next = t;
    }
    head = new_head->next;
    delete new_head;
    return true;
}
