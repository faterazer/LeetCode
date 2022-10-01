class Solution:
    def rotatedDigits_MK1(self, N: int) -> int:
        """Time complexity: O(n)
        Space complexity: O(n)
        """

        # dp[i] = 0, invalid number
        # dp[i] = 1, valid and same number
        # dp[i] = 2, valid and different number
        dp = [0] * (N + 1)
        cnt = 0
        for i in range(N + 1):
            if i == 0 or i == 1 or i == 8:
                dp[i] = 1
            elif i == 2 or i == 5 or i == 6 or i == 9:
                dp[i] = 2
                cnt += 1
            else:
                a, b = dp[i // 10], dp[i % 10]
                if a == 1 and b == 1:
                    dp[i] = 1
                elif a >= 1 and b >= 1:
                    dp[i] = 2
                    cnt += 1
        return cnt

    def rotatedDigits(self, N: int) -> int:
        """Time complexity: O(lgn)
        Space complexity: O(lgn)
        """

        check = [0, 0, 1, -1, -1, 1, 1, -1, 0, 1]

        s = str(N)
        dp = [[-1, -1] for _ in range(len(s))]

        def dfs(pos: int, is_limit: bool, has_diff: bool) -> int:
            if pos == len(s):
                return has_diff
            if not is_limit and dp[pos][has_diff] >= 0:
                return dp[pos][has_diff]

            res = 0
            lim = int(s[pos]) if is_limit else 9
            for i in range(lim + 1):
                if check[i] >= 0:
                    res += dfs(pos + 1, is_limit and i == lim, has_diff or check[i] == 1)
            if not is_limit:
                dp[pos][has_diff] = res
            return res

        return dfs(0, True, False)
