class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def reverseList_MK1(self, head: ListNode) -> ListNode:
        '''
        Iterative version.
        '''
        prev, curr = None, head
        while curr:
            tmp = curr.next
            curr.next = prev
            prev = curr
            curr = tmp
        return prev

    def reverseList(self, head: ListNode) -> ListNode:
        '''
        Recursive version
        '''
        if not head or not head.next:
            return head
        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return new_head
