class Solution:
    def countPoints(self, rings: str) -> int:
        cnt = [0] * 10
        for color, rod in zip(rings[0::2], rings[1::2]):
            cnt[int(rod)] |= 1 << ("RGB".index(color))
        return sum(e == 7 for e in cnt)
