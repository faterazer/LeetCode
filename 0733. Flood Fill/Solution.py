from typing import List


class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        m, n = len(image), len(image[0])
        originColor = image[sr][sc]

        def dfsFill(r: int, c: int) -> None:
            image[r][c] = newColor
            for x, y in ((r + 1, c), (r - 1, c), (r, c - 1), (r, c + 1)):
                if 0 <= x < m and 0 <= y < n and image[x][y] == originColor:
                    dfsFill(x, y)
        
        if (originColor != newColor):
            dfsFill(sr, sc)
        return image
