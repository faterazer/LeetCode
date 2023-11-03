# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: "Node" = None, right: "Node" = None, next: "Node" = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


class Solution:
    def connect(self, root: Node) -> Node:
        if not root:
            return root

        def helper(p: Node) -> None:
            if self.last:
                self.last.next = p
            if not self.next_leftmost:
                self.next_leftmost = p
            self.last = p

        leftmost = root
        while leftmost:
            self.last = self.next_leftmost = None
            head = leftmost
            while head:
                if head.left:
                    helper(head.left)
                if head.right:
                    helper(head.right)
                head = head.next
            leftmost = self.next_leftmost
        return root
