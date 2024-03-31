class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        cnt = 1
        for p in preorder.split(","):
            if cnt == 0:
                return False
            if p == "#":
                cnt -= 1
            else:
                cnt += 1
        return cnt == 0
