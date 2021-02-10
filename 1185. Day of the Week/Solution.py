class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        dayOfWeek = ("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday")
        if month < 3:
            month += 12
            year -= 1
        c, y = year // 100, year % 100
        w = (c // 4 - 2 * c + y + y // 4 + 13 * (month + 1) // 5 + day - 1) % 7
        return dayOfWeek[(w + 7) % 7]
