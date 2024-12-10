import numpy as np

MOD = 1_000_000_007


class Solution:
    def knightDialer(self, n: int) -> int:
        f = np.ones((10, 1), dtype=np.int64)
        M = np.array(
            [
                [0, 0, 0, 0, 1, 0, 1, 0, 0, 0],
                [0, 0, 0, 0, 0, 0, 1, 0, 1, 0],
                [0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
                [0, 0, 0, 0, 1, 0, 0, 0, 1, 0],
                [1, 0, 0, 1, 0, 0, 0, 0, 0, 1],
                [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
                [1, 1, 0, 0, 0, 0, 0, 1, 0, 0],
                [0, 0, 1, 0, 0, 0, 1, 0, 0, 0],
                [0, 1, 0, 1, 0, 0, 0, 0, 0, 0],
                [0, 0, 1, 0, 1, 0, 0, 0, 0, 0],
            ],
            dtype=np.int64,
        )

        n -= 1
        while n:
            if n & 1:
                f = M @ f % MOD
            M = M @ M % MOD
            n >>= 1

        return int(f.sum() % MOD)
