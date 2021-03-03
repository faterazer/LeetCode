class Solution {
    private int zellerDays(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        if (month < 3) {
            year--;
            month += 12;
        }
        return (year - 1) * 365 + year / 4 - year / 100 + year / 400 + (month - 1) * 28 + 13 * (month + 1) / 5 - 7 + day;
    }

    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(zellerDays(date1) - zellerDays(date2));
    }
}
