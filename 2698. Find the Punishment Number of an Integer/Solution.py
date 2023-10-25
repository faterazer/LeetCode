class Solution:
    def punishmentNumber(self, n: int) -> int:
        def is_punishment_number(x: int, need: int) -> bool:
            if x == need:
                return True
            cur, power = 0, 1
            while x:
                cur = x % 10 * power + cur
                x //= 10
                power *= 10
                if is_punishment_number(x, need - cur):
                    return True
            return False

        res = 0
        for i in range(1, n + 1):
            if is_punishment_number(i * i, i):
                res += i * i
        return res
