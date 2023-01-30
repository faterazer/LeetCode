class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        i, p = 0, list1
        while i < a - 1:
            p = p.next
            i += 1
        q = p
        while i <= b:
            q = q.next
            i += 1
        p.next = list2
        while p.next:
            p = p.next
        p.next = q
        return list1
