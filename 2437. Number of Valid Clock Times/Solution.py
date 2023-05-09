class Solution:
    def countTime(self, time: str) -> int:
        hc = mc = 1
        if time[0] == time[1] == "?":
            hc = 24
        elif time[0] == "?":
            hc = 3 if time[1] < "4" else 2
        elif time[1] == "?":
            hc = 10 if time[0] < "2" else 4

        if time[3] == "?":
            mc *= 6
        if time[4] == "?":
            mc *= 10
        return hc * mc
