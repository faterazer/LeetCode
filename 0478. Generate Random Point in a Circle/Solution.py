import math
from typing import List
import random


class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        r, theta = math.sqrt(random.uniform(0, 1.0)), random.uniform(0, 1.0) * 2 * math.pi
        return [self.x_center + r * math.cos(theta) * self.radius, self.y_center + r * math.sin(theta) * self.radius]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
