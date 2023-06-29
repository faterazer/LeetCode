from typing import List


class Solution:
    def strobogrammaticInRange(self, low: str, high: str) -> int:
        ans = 0

        def check(s: str) -> bool:
            return int(low) <= int(s) <= int(high)

        def helper(n: int, flag: bool) -> List[str]:
            nonlocal ans
            if n == 0:
                return [""]
            if n == 1:
                ans += sum(check(s) for s in ["0", "1", "8"])
                return ["0", "1", "8"]

            candidates = ("11", "69", "88", "96", "00")
            substr = helper(n - 2, False)
            res = []
            for prefix, suffix in candidates:
                if flag and prefix == "0":
                    break
                for s in substr:
                    res.append(prefix + s + suffix)
                    ans += check(res[-1]) and res[-1][0] != "0"
            return res

        helper(len(high), True)
        helper(len(high) - 1, True)
        return ans
