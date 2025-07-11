import heapq


class Solution:
    def maxEvents_MK1(self, events: list[list[int]]) -> int:
        mx = max(events, key=lambda x: x[1])[1]

        groups = [[] for _ in range(mx + 1)]
        for start, end in events:
            groups[start].append(end)

        ans = 0
        min_heap = []
        for day in range(mx + 1):
            while min_heap and min_heap[0] < day:
                heapq.heappop(min_heap)
            for end in groups[day]:
                heapq.heappush(min_heap, end)
            if min_heap:
                heapq.heappop(min_heap)
                ans += 1
        return ans

    def maxEvents_MK2(self, events: list[list[int]]) -> int:
        events.sort(key=lambda x: x[1])
        mx = events[-1][1]
        dsu = list(range(mx + 2))

        def find(x: int) -> int:
            if dsu[x] != x:
                dsu[x] = find(dsu[x])
            return dsu[x]

        ans = 0
        for start, end in events:
            beg = find(start)
            if beg <= end:
                dsu[beg] = find(beg + 1)
                ans += 1
        return ans
