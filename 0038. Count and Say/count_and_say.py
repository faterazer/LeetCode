class Solution:
    def countAndSay(self, n: int) -> str:
        ans = '1'
        for _ in range(n - 1):
            base, temp_ans, count = ans[0], '', 0
            for ch in ans:
                if ch == base:
                    count += 1
                else:
                    temp_ans += str(count) + base
                    base = ch
                    count = 1
            ans = temp_ans + str(count) + base
        return ans
