from typing import List


class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        seen = set()
        res = []
        for f in sorted(folder, key=lambda x: len(x)):
            check = True
            for i in range(2, len(f)):
                if f[i] == "/" and f[:i] in seen:
                    check = False
                    break
            if check:
                res.append(f)
            seen.add(f)
        return res
