import bisect


class Solution:
    def nextGreatestLetter(self, letters: list[str], target: str) -> str:
        index = bisect.bisect(letters, target)
        return letters[index % len(letters)]
