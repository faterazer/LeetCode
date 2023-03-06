class Solution:
    def minimumDeletions_MK1(self, s: str) -> int:
        res = delete = s.count("a")
        for c in s:
            delete -= 1 if c == "a" else -1
            res = min(res, delete)
        return res

    def minimumDeletions_MK2(self, s: str) -> int:
        res = cnt_b = 0
        for c in s:
            if c == "a":
                res = min(res + 1, cnt_b)
            else:
                cnt_b += 1
        return res
