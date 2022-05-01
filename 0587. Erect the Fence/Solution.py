from audioop import cross
from functools import cmp_to_key
from typing import List


class Solution:
    def __cross(self, p: List[int], q: List[int], r: List[int]) -> List[List[int]]:
        return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0])

    def __distanse(self, p: List[int], q: List[int]) -> int:
        return (q[0] - p[0]) * (q[0] - p[0]) + (q[1] - p[1]) * (q[1] - p[1])

    def outerTrees_Jarvis(self, trees: List[List[int]]) -> List[List[int]]:
        leftMost = 0
        for i in range(1, len(trees)):
            if trees[i][0] < trees[leftMost][0] or (trees[i][0] == trees[leftMost][0] and trees[i][1] < trees[leftMost][1]):
                leftMost = i
        
        res = []
        visited = set()
        p = leftMost
        while True:
            q = (p + 1) % len(trees)
            for r in range(len(trees)):
                if self.__cross(trees[p], trees[q], trees[r]) < 0:
                    q = r
            for i in range(len(trees)):
                if i not in visited and i != p and i != q and self.__cross(trees[p], trees[q], trees[i]) == 0:
                    visited.add(i)
                    res.append(trees[i])
            if q not in visited:
                visited.add(q)
                res.append(trees[q])
            p = q
            if p == leftMost:
                break
        return res

    def outerTrees_Graham(self, trees: List[List[int]]) -> List[List[int]]:
        if len(trees) < 4:
            return trees
        leftMost = 0
        for i in range(1, len(trees)):
            if trees[i][0] < trees[leftMost][0] or (trees[i][0] == trees[leftMost][0] and trees[i][1] < trees[leftMost][1]):
                leftMost = i
        
        trees[0], trees[leftMost] = trees[leftMost], trees[0]

        def cmp(a: List[int], b: List[int]) -> int:
            c = self.__cross(trees[0], a, b)
            if c == 0:
                return self.__distanse(trees[0], a) - self.__distanse(trees[0], b)
            else:
                return -c

        trees[1:] = sorted(trees[1:], key=cmp_to_key(cmp))

        r = len(trees) - 2
        while r > 0 and self.__cross(trees[0], trees[-1], trees[r]) == 0:
            r -= 1
        i, j = r + 1, len(trees) - 1
        while i < j:
            trees[i], trees[j] = trees[j], trees[i]
            i += 1
            j -= 1
        
        stack = [0, 1]
        for i in range(2, len(trees)):
            while len(stack) > 1 and self.__cross(trees[stack[-2]], trees[stack[-1]], trees[i]) < 0:
                stack.pop()
            stack.append(i)
        return [trees[i] for i in stack]

    def outerTrees_Andrew(self, trees: List[List[int]]) -> List[List[int]]:
        n = len(trees)
        if n < 4:
            return trees
        trees.sort()
        hull = [0]
        visited = set()
        for i in range(1, n):
            while len(hull) > 1 and self.__cross(trees[hull[-2]], trees[hull[-1]], trees[i]) < 0:
                visited.remove(hull[-1])
                hull.pop()
            hull.append(i)
            visited.add(i)
        for i in range(n - 2, -1, -1):
            if i not in visited:
                while len(hull) > 1 and self.__cross(trees[hull[-2]], trees[hull[-1]], trees[i]) < 0:
                    visited.remove(hull[-1])
                    hull.pop()
                hull.append(i)
                visited.add(i)
        hull.pop()
        return [trees[i] for i in hull]
