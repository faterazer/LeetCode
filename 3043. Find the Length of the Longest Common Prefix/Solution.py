class Solution:
    def longestCommonPrefix(self, arr1: list[int], arr2: list[int]) -> int:
        prefix_set = set()
        for x in arr1:
            while x not in prefix_set:
                prefix_set.add(x)
                x //= 10

        ans = 0
        for x in arr2:
            while x not in prefix_set:
                x //= 10
            ans = max(ans, x)
        return len(str(ans)) if ans else 0
