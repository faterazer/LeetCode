class Solution:
    def dayOfYear(self, date: str) -> int:
        def isLeapYear(year: int) -> bool:
            return (not (year % 4) and (year % 100)) or not (year % 400)

        dayOfMonth = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        year, month, day = map(int, date.split('-'))
        if month > 2 and isLeapYear(year):
            day += 1
        return day + sum(dayOfMonth[1:month])
