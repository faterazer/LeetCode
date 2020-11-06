class Solution {
    public int minCostToMoveChips(int[] position) {
        int odd = 0, even = 0;
        for (int p : position) {
            if (p % 2 == 0)
                even++;
            else
                odd++;
        }
        return Math.min(odd, even);
    }
}
