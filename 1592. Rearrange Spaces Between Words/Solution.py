class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        spaces = text.count(' ')
        gap = spaces // (len(words) - 1) if len(words) > 1 else 0
        tail = spaces - gap * (len(words) - 1)
        return (' ' * gap).join(words) + ' ' * tail
