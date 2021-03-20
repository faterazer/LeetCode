from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
         st = {path[0] for path in paths}
         for path in paths:
             if path[1] not in st:
                 return path[1]
