from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        slow, fast = head, head.next
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next

        dummy = ListNode()
        fast, slow.next = slow.next, None
        while fast:
            t = fast
            fast = fast.next
            t.next = dummy.next
            dummy.next = t

        p1, p2 = head, dummy.next
        dummy.next = None
        while p1 and p2:
            dummy.next = p1
            p1 = p1.next
            dummy.next.next = p2
            p2 = p2.next
            dummy = dummy.next.next
        dummy.next = p1 if p1 else p2
