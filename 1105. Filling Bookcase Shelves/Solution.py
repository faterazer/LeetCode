from typing import List


class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        f = [0] * (len(books) + 1)
        for i, (thickness, height) in enumerate(books):
            f[i + 1], j = f[i] + height, i - 1
            while j >= 0 and thickness + books[j][0] <= shelfWidth:
                thickness += books[j][0]
                height = max(height, books[j][1])
                f[i + 1] = min(f[i + 1], height + f[j])
                j -= 1
        return f[-1]
