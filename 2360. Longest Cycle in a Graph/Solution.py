class Solution:
    def longestCycle(self, edges: list[int]) -> int:
        n = len(edges)
        vis_time = [0] * n
        ans, cur_time = -1, 1
        for i in range(n):
            cur, start_time = i, cur_time
            while cur != -1 and vis_time[cur] == 0:
                vis_time[cur] = cur_time
                cur_time += 1
                cur = edges[cur]
            if cur != -1 and vis_time[cur] >= start_time:
                ans = max(ans, cur_time - vis_time[cur])
        return ans
