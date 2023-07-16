import string
from collections import defaultdict
from typing import List


class Solution:
    def alienOrder(self, words: List[str]) -> str:
        edges = defaultdict(list)
        in_degree = {c: 0 for w in words for c in w}
        for first, second in zip(words, words[1:]):
            if len(first) > len(second) and first.startswith(second):
                return ""
            for a, b in zip(first, second):
                if a != b:
                    edges[a].append(b)
                    in_degree[b] += 1
                    break
        res = []
        while in_degree:
            if all(in_degree.get(c, -1) != 0 for c in string.ascii_lowercase):
                return ""
            for c in string.ascii_lowercase:
                if in_degree.get(c, -1) == 0:
                    break
            res.append(c)
            for neighbour in edges[c]:
                in_degree[neighbour] -= 1
            edges.pop(c)
            in_degree.pop(c)
        return "".join(res)
