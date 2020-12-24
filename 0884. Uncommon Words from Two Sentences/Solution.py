import collections
from typing import Coroutine, List


class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        counter = collections.Counter((A + ' ' + B).split())
        return [w for w in counter if counter[w] == 1]
