from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        head, carry = ListNode(), 0
        p = head
        while l1 or l2 or carry:
            a = b = 0
            if l1:
                a, l1 = l1.val, l1.next
            if l2:
                b, l2 = l2.val, l2.next
            p.next = ListNode(a + b + carry)
            p = p.next
            carry, p.val = divmod(p.val, 10)
        return head.next
