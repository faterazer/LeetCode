class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        res = cnt_w = blocks[:k].count("W")
        for a, b in zip(blocks, blocks[k:]):
            cnt_w += (b == "W") - (a == "W")
            res = min(res, cnt_w)
        return res
