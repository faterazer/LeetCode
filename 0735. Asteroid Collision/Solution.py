from typing import List


class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        res = []
        for asteroid in asteroids:
            if asteroid > 0:
                stack.append(asteroid)
                continue
            while stack and stack[-1] + asteroid < 0:
                stack.pop()
            if not stack:
                res.append(asteroid)
            elif stack[-1] + asteroid == 0:
                stack.pop()
        return res + stack
