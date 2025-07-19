class Solution:
    def removeSubfolders(self, folder: list[str]) -> list[str]:
        folder.sort()
        ans = [folder[0]]
        for s in folder[1:]:
            last = ans[-1]
            if not s.startswith(last) or s[len(last)] != "/":
                ans.append(s)
        return ans
