class Solution:
    def minLength(self, s: str) -> int:
        stack = []
        for c in s:
            if stack and ((c == "B" and stack[-1] == "A") or (c == "D" and stack[-1] == "C")):
                stack.pop()
            else:
                stack.append(c)
        return len(stack)
