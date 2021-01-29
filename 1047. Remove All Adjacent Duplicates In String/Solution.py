class Solution:
    def removeDuplicates(self, S: str) -> str:
        res = []
        for ch in S:
            if len(res) and res[-1] == ch:
                res.pop()
            else:
                res.append(ch)
        return ''.join(res)
