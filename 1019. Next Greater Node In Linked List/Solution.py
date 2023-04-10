from typing import List, Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        res, stack = [], []
        while head:
            while stack and head.val > res[stack[-1]]:
                res[stack.pop()] = head.val
            stack.append(len(res))
            res.append(head.val)
            head = head.next
        while stack:
            res[stack.pop()] = 0
        return res
