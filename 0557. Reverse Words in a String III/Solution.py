class Solution:
    def reverseWords_MK1(self, s: str) -> str:
        return ' '.join([word[::-1] for word in s.split(' ')])

    def reverseWords_MK2(self, s: str) -> str:
        return ' '.join(s.split(' ')[::-1])[::-1]
