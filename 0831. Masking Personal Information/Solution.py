class Solution:
    def maskPII(self, s: str) -> str:
        at = s.find("@")
        if at >= 0:
            return (s[0] + "*" * 5 + s[at - 1 :]).lower()
        s = "".join(c for c in s if c.isdigit())
        return ["", "+*-", "+**-", "+***-"][len(s) - 10] + "***-***-" + s[-4:]
