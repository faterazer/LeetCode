import string
from typing import List


class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        tree = {c: c for c in string.ascii_lowercase}

        def findRoot(x: str) -> str:
            if tree[x] == x:
                return x
            tree[x] = findRoot(tree[x])
            return tree[x]

        for a, e, _, b in equations:
            if e == "=":
                tree[findRoot(a)] = findRoot(b)
        return all(findRoot(a) != findRoot(b) for a, e, _, b in equations if e == "!")
