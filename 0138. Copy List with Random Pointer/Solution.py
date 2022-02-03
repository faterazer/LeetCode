from typing import Optional


class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        if not head:
            return None
        p = head
        while p:
            q = Node(p.val, p.next)
            p.next = q
            p = q.next
        p = head
        while p:
            if p.random:
                p.next.random = p.random.next
            p = p.next.next
        r = head.next
        p = head
        while p:
            q = p.next
            p.next = q.next
            p = q.next
            if p:
                q.next = p.next
        return r
