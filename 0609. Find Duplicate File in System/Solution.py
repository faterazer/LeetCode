from collections import defaultdict
from typing import List


class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        mapper = defaultdict(list)
        for path in paths:
            dir_path, files = path.split()
            for file in files:
                l, r = file.index('('), file.index(')')
                filename, content = file[:l], file[l+1:r]
                mapper[content].append(dir_path + '/' + filename)
        return [v for v in mapper.values() if len(v) > 1]
