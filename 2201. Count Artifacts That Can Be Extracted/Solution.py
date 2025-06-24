class Solution:
    def digArtifacts(self, n: int, artifacts: list[list[int]], dig: list[list[int]]) -> int:
        grid = [[False] * n for _ in range(n)]
        for r, c in dig:
            grid[r][c] = True

        ans = 0
        for r1, c1, r2, c2 in artifacts:
            can_extract = True
            for r in range(r1, r2 + 1):
                for c in range(c1, c2 + 1):
                    if not grid[r][c]:
                        can_extract = False
                        break
                if not can_extract:
                    break
            ans += can_extract
        return ans
