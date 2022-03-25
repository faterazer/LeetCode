import java.util.Arrays;

class Solution {
    public int twoCitySchedCost(int[][] costs) {
        Arrays.sort(costs, (o1, o2) -> o2[1] - o2[0] - (o1[1] - o1[0]));
        int n = costs.length / 2, res = 0;
        for (int i = 0; i < n; ++i) {
            res += costs[i][0] + costs[i + n][1];
        }
        return res;
    }
}
