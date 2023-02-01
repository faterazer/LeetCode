class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        cur, mapping = ord("a"), {}
        for c in key:
            if c != " " and c not in mapping:
                mapping[c] = chr(cur)
                cur += 1
        return "".join(mapping.get(c, " ") for c in message)
