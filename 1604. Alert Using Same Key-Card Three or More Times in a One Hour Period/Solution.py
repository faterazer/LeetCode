from typing import List


class Solution:
    def alertNames(self, keyName: List[str], keyTime: List[str]) -> List[str]:
        def minutesOfDay(time: str) -> int:
            h, m = int(time[:2]), int(time[3:])
            return h * 60 + m
        
        map = {}
        for name, time in zip(keyName, keyTime):
            map.setdefault(name, []).append(minutesOfDay(time))
        
        res = []
        for name, records in map.items():
            records.sort()
            if any(a - b <= 60 for a, b in zip(records[2:], records)):
                res.append(name)
        return sorted(res)
