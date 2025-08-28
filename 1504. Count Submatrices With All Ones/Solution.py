class Solution:
    def numSubmat(self, mat: list[list[int]]) -> int:
        m, n = len(mat), len(mat[0])
        height = [0] * n
        ans = 0
        for i in range(m):
            mono_stack = [-1]
            for j in range(n):
                height[j] = height[j] + 1 if mat[i][j] == 1 else 0
                while len(mono_stack) > 1 and height[j] <= height[mono_stack[-1]]:
                    mono_stack.pop()
                last = mono_stack[-1]
                mono_stack.append(j)
                mat[i][j] = height[j] * (j - last)
                if last != -1:
                    mat[i][j] += mat[i][last]
                ans += mat[i][j]
        return ans
