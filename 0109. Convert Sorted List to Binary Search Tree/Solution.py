from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def getLength(head: ListNode) -> int:
            res = 0
            while head:
                res += 1
                head = head.next
            return res

        def buildTree(left: int, right: int) -> TreeNode:
            if left > right:
                return None

            nonlocal head
            mid = left + ((right - left) // 2)
            root = TreeNode()
            root.left = buildTree(left, mid - 1)
            root.val = head.val
            head = head.next
            root.right = buildTree(mid + 1, right)
            return root

        n = getLength(head)
        return buildTree(0, n - 1)
