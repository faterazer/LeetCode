# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergeTwoLists_MK1(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        elif l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

    def mergeTwoLists_MK2(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(None)
        hp = head
        while l1 and l2:
            if l1.val < l2.val:
                hp.next = l1
                l1 = l1.next
            else:
                hp.next = l2
                l2 = l2.next
            hp = hp.next
        hp.next = l1 if not l2 else l2
        return head.next
