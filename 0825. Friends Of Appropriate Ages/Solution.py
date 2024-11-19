from typing import List


class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        age_cnt = [0] * 121
        for age in ages:
            age_cnt[age] += 1

        ans, cnt, age_y = 0, 0, 14
        for age_x in range(14, 121):
            cnt += age_cnt[age_x]
            if 2 * age_y <= age_x + 14:
                cnt -= age_cnt[age_y]
                age_y += 1
            if cnt > 0:
                ans += age_cnt[age_x] * cnt - age_cnt[age_x]
        return ans
