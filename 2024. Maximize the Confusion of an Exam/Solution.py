class Solution:
    def maxConsecutiveAnswers_MK1(self, answerKey: str, k: int) -> int:
        
        def helper(answerKey: str, k: int, c: str) -> int:
            l = r = cnt = res = 0
            while r < len(answerKey):
                cnt += answerKey[r] != c
                while cnt > k:
                    cnt -= answerKey[l] != c
                    l += 1
                res = max(res, r - l + 1)
                r += 1
            return res

        return max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'))

    def maxConsecutiveAnswers_MK2(self, answerKey: str, k: int) -> int:
        t_cnt = f_cnt = res = 0
        for i in range(len(answerKey)):
            if answerKey[i] == 'T':
                t_cnt += 1
            else:
                f_cnt += 1
            if min(t_cnt, f_cnt) <= k:
                res += 1
            elif answerKey[i - res] == 'T':
                t_cnt -= 1
            else:
                f_cnt -= 1
        return res
