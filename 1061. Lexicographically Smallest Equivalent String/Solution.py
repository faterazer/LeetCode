from string import ascii_lowercase


class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        DSU = {c: c for c in ascii_lowercase}

        def find(x: str) -> str:
            if DSU[x] != x:
                DSU[x] = find(DSU[x])
            return DSU[x]

        def merge(x: str, y: str) -> None:
            small, big = sorted((find(x), find(y)))
            DSU[big] = small

        for x, y in zip(s1, s2):
            merge(x, y)

        return "".join(find(c) for c in baseStr)
