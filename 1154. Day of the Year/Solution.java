class Solution {
    private final int[] dayOfMonth = new int[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    public int dayOfYear(String date) {
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));
        if (month > 2 && isLeapYear(year)) {
            day++;
        }
        for (int i = 1; i < month; i++) {
            day += dayOfMonth[i];
        }
        return day;
    }
}
