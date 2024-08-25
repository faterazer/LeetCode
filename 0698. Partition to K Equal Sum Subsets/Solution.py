from typing import List


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if total % k != 0:
            return False

        target = total // k
        nums.sort(reverse=True)
        visited = [False] * len(nums)

        def dfs(idx: int, cur: int, cnt: int) -> bool:
            if cnt == k - 1:
                return True
            if cur == target:
                return dfs(cnt + 1, 0, cnt + 1)

            for i in range(idx, len(nums)):
                if visited[i] or cur + nums[i] > target:
                    continue
                visited[i] = True
                if dfs(i + 1, cur + nums[i], cnt):
                    return True
                visited[i] = False
                if cur == 0:
                    break
            return False

        return dfs(0, 0, 0)
