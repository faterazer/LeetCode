from typing import List


class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string."""
        return "".join([f"{len(s)}/{s}" for s in strs])

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings."""
        res = []
        i = 0
        while i < len(s):
            j = s.find("/", i)
            n = int(s[i:j])
            res.append(s[j + 1 : j + 1 + n])
            i = j + n + 1
        return res


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
