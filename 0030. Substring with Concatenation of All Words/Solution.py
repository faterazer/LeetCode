from collections import Counter
from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        word_cnt = Counter(words)
        word_len, n = len(words[0]), len(s)
        all_words_len = len(words) * word_len
        res = []
        for i in range(word_len):
            if i + all_words_len > n:
                break
            left, right = i, i + all_words_len - word_len
            tmp_cnt = Counter(s[j:j+word_len] for j in range(left, right, word_len))
            while right < n:
                tmp_cnt[s[right:right+word_len]] += 1
                if tmp_cnt == word_cnt:
                    res.append(left)
                tmp_cnt[s[left:left+word_len]] -= 1
                left += word_len
                right += word_len
        return res
