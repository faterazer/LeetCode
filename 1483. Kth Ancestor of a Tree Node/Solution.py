from typing import List


class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        m = n.bit_length()
        self.ancestors = [[-1] * m for _ in range(n)]
        for i, p in enumerate(parent):
            self.ancestors[i][0] = p
        for i in range(1, m):
            for j in range(n):
                if self.ancestors[j][i - 1] != -1:
                    self.ancestors[j][i] = self.ancestors[self.ancestors[j][i - 1]][i - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        m = k.bit_length()
        for i in range(m):
            if k & (1 << i):
                node = self.ancestors[node][i]
                if node == -1:
                    break
        return node


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
