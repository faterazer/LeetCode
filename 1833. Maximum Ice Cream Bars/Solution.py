class Solution:
    def maxIceCream(self, costs: list[int], coins: int) -> int:
        mx = max(costs)
        cnt = [0] * (mx + 1)
        for c in costs:
            cnt[c] += 1

        result = 0
        for cost in range(1, mx + 1):
            if coins < cost:
                break
            num = min(cnt[cost], coins // cost)
            coins -= num * cost
            result += num
        return result
