class Solution:
    def strStr_MK1(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

    def strStr_MK2(self, haystack: str, needle: str) -> int:
        for i in range(len(haystack) - len(needle) + 1):
            if haystack[i:i + len(needle)] == needle:
                return i
        return -1

    # KMP
    def strStr_MK3(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0
        nextlist = [0] * len(needle)
        j = 0
        for i in range(1, len(needle)):
            while j > 0 and needle[i] != needle[j]:
                j = nextlist[j - 1]
            if needle[i] == needle[j]:
                j += 1
            nextlist[i] = j
        j = 0
        for i, c in enumerate(haystack):
            while j > 0 and c != needle[j]:
                j = nextlist[j - 1]
            if c == needle[j]:
                j += 1
            if j == len(needle):
                return i - j + 1
        return -1
