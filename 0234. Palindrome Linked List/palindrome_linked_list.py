class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        slow, fast, new_head = head, head, ListNode(0)
        while fast and fast.next:
            tp = slow
            slow = slow.next
            fast = fast.next.next
            tp.next = new_head.next
            new_head.next = tp
        
        first_head = new_head.next
        second_head = slow.next if fast else slow
        while first_head and second_head:
            if first_head.val != second_head.val:
                return False
            first_head = first_head.next
            second_head = second_head.next
        p, t, new_head.next = new_head.next, None, slow
        while p:
            t = p
            p = p.next
            t.next = new_head.next
            new_head.next = t
        head = new_head.next
        return True
