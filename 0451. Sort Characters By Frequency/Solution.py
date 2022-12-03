from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        c = sorted(Counter(s).items(), key=lambda x: x[1], reverse=True)
        return "".join([ch * freq for ch, freq in c])
