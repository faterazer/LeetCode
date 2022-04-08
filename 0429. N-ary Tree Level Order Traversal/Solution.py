from typing import List


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    def levelOrder(self, root: Node) -> List[List[int]]:
        res = []
        if not root:
            return res
        q = [root]
        while q:
            res.append([node.val for node in q])
            q = [child for node in q for child in node.children]
        return res
        