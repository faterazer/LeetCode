from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        n = 0
        p = head
        while p:
            n += 1
            p = p.next

        m = n // 2
        buffer = [0] * m
        p = head
        for i in range(m):
            buffer[i] = p.val
            p = p.next

        result = 0
        for i in range(m, n):
            result = max(result, buffer[n - 1 - i] + p.val)
            p = p.next
        return result
