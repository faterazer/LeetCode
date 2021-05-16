class Solution:
    def maximumTime(self, time: str) -> str:
        res = list(time)
        if res[0] == '?':
            res[0] = '2' if res[1] == '?' or res[1] < '4' else '1'
        if res[1] == '?':
            res[1] = '3' if res[0] == '2' else '9'
        if res[3] == '?':
            res[3] = '5'
        if res[4] == '?':
            res[4] = '9'
        return ''.join(res)
