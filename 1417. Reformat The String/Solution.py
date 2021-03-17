class Solution:
    def reformat(self, s: str) -> str:
        s1 = [x for x in s if x.isalpha()]
        s2 = [x for x in s if x.isdigit()]
        if abs(len(s1) - len(s2)) > 1:
            return ''
        res = [None] * len(s)
        if len(s1) > len(s2):
            res[0::2] = s1
            res[1::2] = s2
        else:
            res[1::2] = s1
            res[0::2] = s2
        return ''.join(res)
