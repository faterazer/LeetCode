from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSameTree_MK1(self, p: TreeNode, q: TreeNode) -> bool:
        '''
        Recursion.
        '''
        if p and q and p.val == q.val:
            return self.isSameTree_MK1(p.left, q.left) and self.isSameTree_MK1(p.right, q.right)
        elif not p and not q:
            return True
        else:
            return False

    def __check(self, p: TreeNode, q: TreeNode) -> bool:
        if p and q and p.val == q.val:
            return True
        elif not p and not q:
            return True
        else:
            return False
    
    def isSameTree_MK2(self, p: TreeNode, q: TreeNode) -> bool:
        '''
        Iteration.
        '''
        deq = deque([(p, q)])
        while deq:
            p, q = deq.popleft()
            if not self.__check(p, q):
                return False
            if p:
                deq.append((p.left, q.left))
                deq.append((p.right, q.right))
        return True
