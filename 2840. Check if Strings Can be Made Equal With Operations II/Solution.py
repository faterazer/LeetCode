from collections import Counter
from itertools import islice


class Solution:
    def checkStrings(self, s1: str, s2: str) -> bool:
        return (
            Counter(islice(s1, 0, None, 2)) == Counter(islice(s2, 0, None, 2))
            and
            Counter(islice(s1, 1, None, 2)) == Counter(islice(s2, 1, None, 2))
        )
