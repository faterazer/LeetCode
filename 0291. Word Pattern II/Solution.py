class Solution:
    def wordPatternMatch(self, pattern: str, s: str) -> bool:
        table, seen = {}, set()

        def helper(pi: int, si: int) -> bool:
            if pi == len(pattern) and si == len(s):
                return True
            if pi == len(pattern) or si == len(s):
                return False

            pc = pattern[pi]
            if pc in table:
                ps = table[pc]
                if s[si:].startswith(ps):
                    return helper(pi + 1, si + len(ps))
                else:
                    return False

            buff = []
            for i in range(si, len(s)):
                buff.append(s[i])
                ps = "".join(buff)
                if ps in seen:
                    continue
                table[pc] = ps
                seen.add(ps)
                if helper(pi + 1, i + 1):
                    return True
                seen.remove(ps)
                table.pop(pc)

            return False

        return helper(0, 0)
