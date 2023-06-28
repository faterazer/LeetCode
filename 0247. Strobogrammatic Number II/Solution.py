from typing import List


class Solution:
    def findStrobogrammatic(self, n: int, flag: bool = True) -> List[str]:
        if n == 0:
            return [""]
        if n == 1:
            return ["0", "1", "8"]

        candidates = ("11", "69", "88", "96", "00")
        substr = self.findStrobogrammatic(n - 2, False)
        res = []
        for prefix, suffix in candidates:
            if flag and prefix == "0":
                break
            for s in substr:
                res.append(prefix + s + suffix)
        return res
