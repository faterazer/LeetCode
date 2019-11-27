from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def maxDepth_MK1(self, root: TreeNode) -> int:
        '''
        Recursive, DFS
        '''
        if not root:
            return 0
        else:
            return 1 + max(self.maxDepth_MK1(root.left), self.maxDepth_MK1(root.right))

    def maxDepth_MK2(self, root: TreeNode) -> int:
        '''
        Iterative, DFS
        '''
        stack = []
        if root:
            stack.append((root, 1))
        depth = 0
        while stack:
            curr_node, curr_depth = stack.pop()
            depth = max(depth, curr_depth)
            if curr_node.left:
                stack.append((curr_node.left, curr_depth + 1))
            if curr_node.right:
                stack.append((curr_node.right, curr_depth + 1))
        return depth

    def maxDepth_MK3(self, root: TreeNode) -> int:
        '''
        Iterative: BFS
        '''
        depth = 0
        deq = deque([])
        if root:
            deq.append(root)
        while deq:
            depth += 1
            size = len(deq)
            for _ in range(0, size):
                p = deq.popleft()
                if p.left:
                    deq.append(p.left)
                if p.right:
                    deq.append(p.right)
        return depth
