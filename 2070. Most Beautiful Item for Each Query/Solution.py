import bisect


class Solution:
    def maximumBeauty(self, items: list[list[int]], queries: list[int]) -> list[int]:
        items.sort(key=lambda x: x[0])
        last = 0
        for i in range(1, len(items)):
            if items[i][1] > items[last][1]:
                last += 1
                items[last] = items[i]
        items = items[: last + 1]

        ans = []
        for i, q in enumerate(queries):
            queries[i] = (q, i)
            j = bisect.bisect_right(items, q, key=lambda x: x[0])
            ans.append(items[j - 1][1] if j > 0 else 0)
        return ans
