class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        l = "L"
        dominoes = list(dominoes)
        i, n = 0, len(dominoes)
        while i < n:
            j = i
            while j < n and dominoes[j] == ".":
                j += 1

            r = dominoes[j] if j < n else "R"
            if l == r:
                while i < j:
                    dominoes[i] = l
                    i += 1
            elif l == "R" and r == "L":
                k = j - 1
                while i < k:
                    dominoes[i] = l
                    i += 1
                    dominoes[k] = r
                    k -= 1
            i = j + 1
            l = r
        return "".join(dominoes)
