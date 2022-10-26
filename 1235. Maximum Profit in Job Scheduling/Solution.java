import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeMap;

class Solution {
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][];
        for (int i = 0; i < n; i++) {
            jobs[i] = new int[]{startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, Comparator.comparingInt(x -> x[1]));

        TreeMap<Integer, Integer> dp = new TreeMap<>();
        dp.put(0, 0);
        for (int[] job : jobs) {
            int curProfit = dp.floorEntry(job[0]).getValue() + job[2];
            dp.put(job[1], Math.max(dp.lastEntry().getValue(), curProfit));
        }
        return dp.lastEntry().getValue();
    }
}
