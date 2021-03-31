class Solution:
    def reformatDate(self, date: str) -> str:
        m2n = {"Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04", "May": "05", "Jun": "06",
               "Jul": "07", "Aug": "08", "Sep": "09", "Oct": "10", "Nov": "11", "Dec": "12"}
        day, month, year = date.split(' ')
        return '-'.join([year, m2n[month], day[0:-2].zfill(2)])
