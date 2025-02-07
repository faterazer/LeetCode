from collections import defaultdict
from typing import List


class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ball2color = {}
        color2cnt = defaultdict(int)
        ans = []
        for ball, color in queries:
            old_color = ball2color.get(ball, 0)  # 题目限制里没有 0 颜色，所以这里用 0 表示没有颜色
            if old_color in color2cnt:
                color2cnt[old_color] -= 1
                if color2cnt[old_color] == 0:
                    color2cnt.pop(old_color)
            ball2color[ball] = color
            color2cnt[color] += 1
            ans.append(len(color2cnt))
        return ans
