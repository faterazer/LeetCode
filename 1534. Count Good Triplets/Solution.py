class Solution:
    def countGoodTriplets_MK1(self, arr: list[int], a: int, b: int, c: int) -> int:
        res = 0
        preSum = [0] * 1001
        for j in range(len(arr)):
            for k in range(j + 1, len(arr)):
                if abs(arr[j] - arr[k]) > b:
                    continue
                l = max(0, arr[j] - a, arr[k] - c)
                r = min(1000, arr[j] + a, arr[k] + c)
                if l <= r:
                    res += preSum[r]
                    if l > 0:
                        res -= preSum[l - 1]
            for x in range(arr[j], 1001):
                preSum[x] += 1
        return res

    def countGoodTriplets_MK2(self, arr: list[int], a: int, b: int, c: int) -> int:
        indices = sorted(range(len(arr)), key=lambda i: arr[i])

        ans = 0
        for j in indices:
            y = arr[j]
            left, right = [], []
            for i in indices:
                if i < j and abs(arr[i] - y) <= a:
                    left.append(arr[i])
            for k in indices:
                if k > j and abs(y - arr[k]) <= b:
                    right.append(arr[k])

            k1 = k2 = 0
            for x in left:
                while k2 < len(right) and right[k2] - x <= c:
                    k2 += 1
                while k1 < len(right) and right[k1] - x < -c:
                    k1 += 1
                ans += k2 - k1
        return ans
