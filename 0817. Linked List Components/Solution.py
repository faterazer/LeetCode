from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def numComponents(self, head: Optional[ListNode], nums: List[int]) -> int:
        subset = set(nums)
        res = is_component = 0
        while head:
            if head.val in subset:
                is_component = 1
            else:
                res += is_component
                is_component = 0
            head = head.next
        return res + is_component
