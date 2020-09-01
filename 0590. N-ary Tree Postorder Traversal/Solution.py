from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def postorder(self, root: Node) -> List[int]:
        ret = []
        if not root:
            return ret
        stack = [root]
        while stack:
            node = stack.pop()
            ret.append(node.val)
            stack.extend(node.children)
        return ret[::-1]
