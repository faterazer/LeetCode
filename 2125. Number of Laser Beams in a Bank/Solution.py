class Solution:
    def numberOfBeams(self, bank: list[str]) -> int:
        ans = prev = 0
        for row in bank:
            cnt = row.count("1")
            if cnt > 0:
                ans += prev * cnt
                prev = cnt
        return ans
