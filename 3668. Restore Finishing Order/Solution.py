class Solution:
    def recoverOrder(self, order: list[int], friends: list[int]) -> list[int]:
        return [x for x in order if x in set(friends)]
