from math import isqrt


MX = int((10**9) ** 0.5)
primes = []
f = [1] * (MX + 1)

f[0] = f[1] = 0
for i in range(2, MX + 1):
    if f[i]:
        primes.append(i)
    j = 0
    while j < len(primes) and primes[j] * i <= MX:
        f[i * primes[j]] = 0
        if i % primes[j] == 0:
            break
        j += 1
    f[i] += f[i - 1]


class Solution:
    def nonSpecialCount(self, l: int, r: int) -> int:
        return r - l + 1 - f[isqrt(r)] + f[isqrt(l - 1)]
