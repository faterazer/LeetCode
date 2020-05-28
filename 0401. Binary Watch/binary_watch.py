from typing import List


class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        ret = []
        for hour in range(0, 12):
            for minute in range(0, 60):
                if (bin(hour) + bin(minute)).count('1') == num:
                    ret.append('%d:%02d' % (hour, minute))
        return ret
