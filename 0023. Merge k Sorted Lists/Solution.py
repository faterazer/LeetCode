from typing import List, Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        def mergetTwoLists(l1: ListNode, l2: ListNode) -> ListNode:
            dummy = ListNode()
            p = dummy
            while l1 and l2:
                if l1.val <= l2.val:
                    p.next = l1
                    l1 = l1.next
                else:
                    p.next = l2
                    l2 = l2.next
                p = p.next
            p.next = l1 if l1 else l2
            return dummy.next

        def merge(lo: int, hi: int) -> ListNode:
            if lo > hi:
                return None
            if lo == hi:
                return lists[lo]
            mid = lo + (hi - lo) // 2
            return mergetTwoLists(merge(lo, mid), merge(mid + 1, hi))

        return merge(0, len(lists) - 1)
