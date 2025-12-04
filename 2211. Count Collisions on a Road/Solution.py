class Solution:
    def countCollisions(self, directions: str) -> int:
        directions = directions.lstrip("L").rstrip("R")
        return len(directions) - directions.count("S")
