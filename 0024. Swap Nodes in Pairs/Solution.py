from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        p = dummy
        while p.next and p.next.next:
            a, b = p.next, p.next.next
            p.next = b
            a.next = b.next
            b.next = a
            p = a
        return dummy.next
