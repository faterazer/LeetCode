from typing import List


class TireNode:
    List =


class Solution:
    def minimumLengthEncoding_MK1(self, words: List[str]) -> int:
        '''
        暴力哈希
        '''
        hash_set = set(words)
        for word in words:
            for i in range(1, len(word)):
                if word[i:] in hash_set:
                    hash_set.remove(word[i:])
        ans = 0
        for word in hash_set:
            ans += len(word) + 1
        return ans

    def minimumLengthEncoding_MK2(self, words: List[str]) -> int:
        '''
        反转排序
        '''
        words = sorted(w[::-1] for w in words) + ['']
        ans = 0
        for i in range(len(words) - 1):
            if not words[i+1].startswith(words[i]):
                ans += len(words[i]) + 1
        return ans
