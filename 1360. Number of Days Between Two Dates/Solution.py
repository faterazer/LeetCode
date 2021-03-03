class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        def zellerDays(date: str) -> int:
            year, month, day = map(int, date.split('-'))
            if month < 3:
                year -= 1
                month += 12;
            return (year - 1) * 365 + year // 4 - year // 100 + year // 400 + (month - 1) * 28 + 13 * (month + 1) // 5 - 7 + day;
        
        return abs(zellerDays(date1) - zellerDays(date2))
