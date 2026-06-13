class Solution:
    def mapWordWeights(self, words: list[str], weights: list[int]) -> str:
        result = []
        ord_a = ord("a")
        ord_z = ord("z")
        for word in words:
            weight = sum(weights[ord(c) - ord_a] for c in word)
            result.append(chr(ord_z - weight % 26))
        return "".join(result)
