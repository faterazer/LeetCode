class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c == "c":
                if len(stack) < 2 or stack.pop() != "b" or stack.pop() != "a":
                    return False
            else:
                stack.append(c)
        return not stack
