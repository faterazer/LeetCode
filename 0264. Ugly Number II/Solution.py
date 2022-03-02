class Solution:
    def nthUglyNumber(self, n: int) -> int:
        buff = [0] * n
        buff[0] = 1
        p2, p3, p5 = 0, 0, 0
        for i in range(1, len(buff)):
            buff[i] = min(min(buff[p2] * 2, buff[p3] * 3), buff[p5] * 5)
            if buff[i] == buff[p2] * 2:
                p2 += 1
            if buff[i] == buff[p3] * 3:
                p3 += 1
            if buff[i] == buff[p5] * 5:
                p5 += 1
        return buff[n - 1]
