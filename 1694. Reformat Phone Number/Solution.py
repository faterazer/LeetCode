class Solution:
    def reformatNumber(self, number: str) -> str:
        res = []
        count = 0
        for c in number:
            if not c.isdigit():
                continue
            count += 1
            if (len(res) + 1) % 4 == 0:
                res.append('-')
            res.append(c)
        if count > 1 and count % 3 == 1:
            res[-2], res[-3] = res[-3], res[-2]
        return ''.join(res)
