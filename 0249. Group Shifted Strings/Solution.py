from typing import List


class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        table = {}
        for s in strings:
            offset = ord(s[0]) - ord("a")
            key = "".join(chr((ord(c) - ord("a") - offset) % 26 + ord("a")) for c in s)
            table.setdefault(key, []).append(s)
        return [v for v in table.values()]
