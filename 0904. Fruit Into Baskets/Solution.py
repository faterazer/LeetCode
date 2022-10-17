from typing import List


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cnt, i = {}, 0
        for j, e in enumerate(fruits):
            cnt[e] = cnt.get(e, 0) + 1
            if len(cnt) > 2:
                cnt[fruits[i]] -= 1
                if cnt[fruits[i]] == 0:
                    cnt.pop(fruits[i])
                i += 1
        return j - i + 1
