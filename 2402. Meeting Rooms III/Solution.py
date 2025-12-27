import heapq


class Solution:
    def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
        meetings.sort(key=lambda x: x[0])
        available = list(range(n))
        occupied = []
        cnt = [0] * n
        for start, end in meetings:
            while occupied and occupied[0][0] <= start:
                heapq.heappush(available, heapq.heappop(occupied)[1])
            if available:
                room = heapq.heappop(available)
                cnt[room] += 1
                heapq.heappush(occupied, (end, room))
            else:
                t, room = heapq.heappop(occupied)
                cnt[room] += 1
                heapq.heappush(occupied, (t + end - start, room))
        return cnt.index(max(cnt))
