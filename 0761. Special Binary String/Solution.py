class Solution:
    def makeLargestSpecial(self, s: str) -> str:
        if len(s) <= 2:
            return s

        cnt = i = 0
        subs = []

        for j, c in enumerate(s):
            if c == '1':
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    subs.append('1' + self.makeLargestSpecial(s[i+1:j]) + '0')
                    i = j + 1
        subs.sort(reverse=True)
        return ''.join(subs)
