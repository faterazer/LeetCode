class Solution:
    def residuePrefixes(self, s: str) -> int:
        result = st = 0
        for i, c in enumerate(s):
            st |= 1 << (ord(c) - ord("a"))
            cnt = st.bit_count()
            if cnt == 3:
                break
            if cnt == (i + 1) % 3:
                result += 1
        return result
