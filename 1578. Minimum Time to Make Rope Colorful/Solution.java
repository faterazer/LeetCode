class Solution {
    public int minCost(String colors, int[] neededTime) {
        int maxCost = 0, res = 0;
        for (int i = 0; i < neededTime.length; i++) {
            if (i > 0 && colors.charAt(i) != colors.charAt(i - 1)) {
                maxCost = 0;
            }
            res += Math.min(maxCost, neededTime[i]);
            maxCost = Math.max(maxCost, neededTime[i]);
        }
        return res;
    }
}
