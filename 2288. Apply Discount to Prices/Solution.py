class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        d = 1 - discount / 100
        segments = sentence.split()
        for i, s in enumerate(segments):
            if s[0] == "$" and s[1:].isdigit():
                segments[i] = f"${int(s[1:]) * d:.2f}"
        return " ".join(segments)
