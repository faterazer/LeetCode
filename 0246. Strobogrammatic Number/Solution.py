class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        map = {"0": "0", "1": "1", "6": "9", "8": "8", "9": "6"}
        i, j = 0, len(num) - 1
        while i <= j:
            if num[i] not in map or map[num[i]] != num[j]:
                return False
            i += 1
            j -= 1
        return True
