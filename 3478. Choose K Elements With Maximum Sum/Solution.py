import heapq


class Solution:
    def findMaxSum(self, nums1: list[int], nums2: list[int], k: int) -> list[int]:
        n = len(nums1)
        ids = list(range(n))
        ids.sort(key=lambda i: nums1[i])

        ans = [0] * n
        min_heap = []
        total_sum = 0
        for i in range(n):
            idx = ids[i]
            if i > 0 and nums1[idx] == nums1[ids[i - 1]]:
                ans[idx] = ans[ids[i - 1]]
            else:
                ans[idx] = total_sum
            heapq.heappush(min_heap, nums2[idx])
            total_sum += nums2[idx]
            if len(min_heap) > k:
                total_sum -= heapq.heappop(min_heap)
        return ans
