from typing import List


class Solution:
    def expressiveWords(self, s: str, words: List[str]) -> int:
        def isExpressive(s: str, t: str) -> bool:
            sn, tn = len(s), len(t)
            si = ti = 0
            while si < sn and ti < tn:
                if s[si] != t[ti]:
                    return False
                sj = si + 1
                while sj < sn and s[sj] == s[si]:
                    sj += 1
                tj = ti + 1
                while tj < tn and t[tj] == t[ti]:
                    tj += 1

                s_cnt, t_cnt = sj - si, tj - ti
                if (t_cnt < s_cnt and s_cnt < 3) or s_cnt < t_cnt:
                    return False
                si, ti = sj, tj
            return si == sn and ti == tn

        return sum(isExpressive(s, word) for word in words)
