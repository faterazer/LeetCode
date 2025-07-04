from string import ascii_lowercase


class Solution:
    def kthCharacter(self, k: int, operations: list[int]) -> str:
        k -= 1
        m = k.bit_length()
        inc = 0
        for i in range(m):
            inc += k >> i & operations[i]
        return ascii_lowercase[inc % 26]
