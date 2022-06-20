from typing import Dict, List


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

    def minimumLengthEncoding_MK3(self, words: List[str]) -> int:
        '''
        Trie tree
        '''
        root = {}
        leaves = []
        for word in set(words):
            cur = root
            for c in word[::-1]:
                if c not in cur:
                    cur[c] = {}
                cur = cur[c]
            leaves.append((cur, len(word)))

        return sum(depth + 1 for leaf, depth in leaves if not leaf)
