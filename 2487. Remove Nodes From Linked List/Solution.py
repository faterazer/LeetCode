from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head = self.reverseNodes(head)
        p = head
        while p.next:
            if p.val > p.next.val:
                p.next = p.next.next
            else:
                p = p.next
        return self.reverseNodes(head)

    def reverseNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode()
        while head:
            p = head
            head = head.next
            p.next = dummy.next
            dummy.next = p
        return dummy.next
