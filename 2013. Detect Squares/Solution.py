from collections import Counter, defaultdict


class DetectSquares:

    def __init__(self):
        self.row2cnt = defaultdict(Counter)

    def add(self, point: list[int]) -> None:
        r, c = point
        self.row2cnt[r][c] += 1

    def count(self, point: list[int]) -> int:
        ans = 0
        r1, c1 = point
        for c2, cnt in self.row2cnt[r1].items():
            if c2 == c1:
                continue
            d = abs(c2 - c1)
            ans += cnt * self.row2cnt[r1 + d][c1] * self.row2cnt[r1 + d][c2]
            ans += cnt * self.row2cnt[r1 - d][c1] * self.row2cnt[r1 - d][c2]
        return ans


# Your DetectSquares object will be instantiated and called as such:
# obj = DetectSquares()
# obj.add(point)
# param_2 = obj.count(point)
