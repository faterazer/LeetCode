class Solution {
    private static final int[] days = new int[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    private int accumDays(String s) {
        int month = Integer.parseInt(s.substring(0, 2)), day = Integer.parseInt(s.substring(3));
        for (int i = 0; i < month - 1; i++) {
            day += days[i];
        }
        return day;
    }

    public int countDaysTogether(String arriveAlice, String leaveAlice, String arriveBob, String leaveBob) {
        int left = accumDays(arriveAlice.compareTo(arriveBob) > 0 ? arriveAlice : arriveBob);
        int right = accumDays(leaveAlice.compareTo(leaveBob) < 0 ? leaveAlice : leaveBob);
        return Math.max(right - left + 1, 0);
    }
}
