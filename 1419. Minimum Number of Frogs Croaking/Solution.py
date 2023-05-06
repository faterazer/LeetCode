class Solution:
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        cnt = [0] * 5
        res = frogs = 0
        for c in croakOfFrogs:
            i = "croak".find(c)
            cnt[i] += 1
            if i == 0:
                frogs += 1
                res = max(res, frogs)
            elif i == 4:
                frogs -= 1
            else:
                cnt[i - 1] -= 1
                if cnt[i - 1] < 0:
                    return -1
        return res if frogs == 0 else -1
