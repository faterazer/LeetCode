class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        xy = yx = 0
        for a, b in zip(s1, s2):
            if a == b:
                continue
            elif a == "x":
                xy += 1
            else:
                yx += 1
        if xy % 2 != yx % 2:
            return -1
        return xy // 2 + yx // 2 + xy % 2 + yx % 2
