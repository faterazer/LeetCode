from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode()
        tail, p = dummy, head
        while p:
            i = 0
            while p and i < k:
                p = p.next
                i += 1
            if i < k:
                break

            new_tail = head
            while head != p:
                t = head
                head = head.next
                t.next = tail.next
                tail.next = t
            tail = new_tail

        tail.next = head
        return dummy.next
