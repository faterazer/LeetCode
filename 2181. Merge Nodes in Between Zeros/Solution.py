from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeNodes(self, head: Optional[ListNode]) -> Optional[ListNode]:
        p, q = head, head.next
        while q and (q.val or q.next):
            if q.val:
                p.val += q.val
            else:
                p.next = q
                p = p.next
            q = q.next
        p.next = None
        return head
