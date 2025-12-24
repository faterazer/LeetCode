class Solution:
    def minimumBoxes(self, apple: list[int], capacity: list[int]) -> int:
        apple_cnt = sum(apple)
        capacity.sort(reverse=True)
        for i, c in enumerate(capacity):
            apple_cnt -= c
            if apple_cnt <= 0:
                return i + 1
        return -1
