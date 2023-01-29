class Solution:
    def countAsterisks(self, s: str) -> int:
        return sum(ss.count("*") for ss in s.split("|")[::2])
