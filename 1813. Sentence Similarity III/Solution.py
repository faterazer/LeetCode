class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        seg1, seg2 = sentence1.split(), sentence2.split()
        if len(seg1) < len(seg2):
            seg1, seg2 = seg2, seg1
        i = 0
        while i < len(seg2) and seg1[i] == seg2[i]:
            i += 1
        k, j = len(seg1) - 1, len(seg2) - 1
        while j > i and seg1[k] == seg2[j]:
            k -= 1
            j -= 1
        return i == j - 1
