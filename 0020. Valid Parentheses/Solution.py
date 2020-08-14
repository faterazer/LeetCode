class Solution:
    def isValid_MK1(self, s: str) -> bool:
        # The stack to keep track of opening brackets.
        stack = []

        # Hash map for keeping track of mappings. This keeps the code very clean.
        # Also makes adding more types of parentheses eaiser
        mapping = {')': '(', ']': '[', '}': '{'}

        # For every bracket in the expression.
        for ch in s:
            # if the character is an closing bracket
            if ch in mapping:
                # Pop the topmost element from the stack, if it is non empty
                # Otherwise assign a dummy value of '#' to the top_element variable
                top_element = stack.pop() if stack else '#'

                # The mapping for the opening bracket in our hash and the top
                # element of the stack don't match, return False
                if mapping[ch] != top_element:
                    return False
            else:
                # We have an opening bracket, simply push it onto the stack.
                stack.append(ch)

        # In the end, if the stack is empty, then we have a valid expression.
        # The stack won't be empty for cases like ((()
        return not stack

    def isValid_MK2(self, s: str) -> bool:
        while '()' in s or '[]' in s or '{}' in s:
            s = s.replace('()', '')
            s = s.replace('[]', '')
            s = s.replace('{}', '')
        return not s
