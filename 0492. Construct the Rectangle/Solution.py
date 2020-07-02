import math
from typing import List


class Solution:
    def constructRectangle(self, area: int) -> List[int]:
        w = int(math.sqrt(area))
        while (area % w):
            w -= 1
        return  [area // w, w]
