class Solution:
    def maximumRemovals(self, s: str, p: str, removable: list[int]) -> int:
        def check(k: int) -> bool:
            removed = set(removable[:k])
            j = 0
            for i, c in enumerate(s):
                if i not in removed and c == p[j]:
                    j += 1
                    if j == len(p):
                        return True
            return False

        lo, hi = 0, len(removable)
        while lo < hi:
            mid = lo + (hi - lo) // 2 + 1
            if check(mid):
                lo = mid
            else:
                hi = mid - 1
        return lo
