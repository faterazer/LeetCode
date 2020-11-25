import collections
import string
from typing import Counter


class Solution:
    def sortString(self, s: str) -> str:
        counter, res = collections.Counter(s), []
        while counter:
            for traverse in string.ascii_lowercase, reversed(string.ascii_lowercase):
                res += [c for c in traverse if c in counter]
                counter -= dict.fromkeys(counter, 1)
        return ''.join(res)
