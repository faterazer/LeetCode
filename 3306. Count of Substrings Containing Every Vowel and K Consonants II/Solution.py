from collections import defaultdict


class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        vowels = set("aeiou")

        def f(K: int) -> int:
            vowel_cnt = defaultdict(int)
            ans = left = consonants = 0
            for c in word:
                if c in vowels:
                    vowel_cnt[c] += 1
                else:
                    consonants += 1
                while len(vowel_cnt) == 5 and consonants >= K:
                    c = word[left]
                    if c in vowels:
                        vowel_cnt[c] -= 1
                        if vowel_cnt[c] == 0:
                            vowel_cnt.pop(c)
                    else:
                        consonants -= 1
                    left += 1
                ans += left
            return ans

        return f(k) - f(k + 1)
