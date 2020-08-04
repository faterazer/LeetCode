from collections import deque


class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children


class Solution:
    # DFS
    def maxDepth_MK1(self, root: Node) -> int:
        if not root:
            return 0
        depth = 0
        for child in root.children:
            depth = max(depth, self.maxDepth_MK1(child))
        return depth + 1

    def maxDepth_MK2(self, root: Node) -> int:
        if not root:
            return 0
        depth = 0
        queue = deque()
        queue.append((root, 1))
        while queue:
            node, level = queue.popleft()
            depth = max(depth, level)
            for child in node.children:
                queue.append((child, depth + 1))
        return depth
