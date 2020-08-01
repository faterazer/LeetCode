import re


class Solution:
    def checkRecord_MK1(self, s: str) -> bool:
        absent, contin_late = 0, 0
        for ch in s:
            if ch == 'L':
                contin_late += 1
            else:
                contin_late = 0
                if ch == 'A':
                    absent += 1
            if absent > 1 or contin_late > 2:
                return False
        return True

    def checkRecord_MK2(self, s: str) -> bool:
        return s.count('A') <= 1 and s.count('LLL') == 0

    def checkRecord_MK3(self, s: str) -> bool:
        return not re.search('A.*A|LLL', s)
