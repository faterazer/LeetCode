class Robot:

    def __init__(self, width: int, height: int):
        self.w = width
        self.h = height
        self.pos = 0
        self.perimeter = 2 * width + 2 * height - 4

    def step(self, num: int) -> None:
        self.pos = (self.pos + num) % self.perimeter
        if self.pos == 0:
            self.pos = self.perimeter

    def getPos(self) -> list[int]:
        if self.pos == 0 or self.pos == self.perimeter:
            return [0, 0]
        if self.pos < self.w:
            return [self.pos, 0]
        if self.pos < self.w + self.h - 1:
            return [self.w - 1, self.pos - self.w + 1]
        if self.pos < 2 * self.w + self.h - 2:
            return [self.w - 1 - (self.pos - self.w - self.h + 2), self.h - 1]
        return [0, self.h - 1 - (self.pos - 2 * self.w - self.h + 3)]

    def getDir(self) -> str:
        if self.pos < self.w:
            return "East"
        if self.pos < self.w + self.h - 1:
            return "North"
        if self.pos < self.w * 2 + self.h - 2:
            return "West"
        return "South"


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()
