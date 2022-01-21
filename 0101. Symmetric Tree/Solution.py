from collections import deque


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __judge(self, r1: TreeNode, r2: TreeNode) -> bool:
        if not r1 and not r2:
            return True
        elif not r1 or not r2:
            return False
        else:
            return r1.val == r2.val and self.__judge(r1.left, r2.right) and self.__judge(r1.right, r2.left)

    def isSymmetric_MK1(self, root: TreeNode) -> bool:
        '''
        Recursive.
        '''
        if not root:
            return True
        return self.__judge(root.left, root.right)

    def isSymmetric_MK2(self, root: TreeNode) -> bool:
        if not root:
            return True

        que = deque([(root.left, root.right)])
        while que:
            t1, t2 = que.popleft()
            if not t1 and not t2:
                continue
            elif not t1 or not t2:
                return False
            elif t1.val != t2.val:
                return False
            que.append((t1.left, t2.right))
            que.append((t1.right, t2.left))
        return True
