class Solution {
    public int xorOperation(int n, int start) {
        int res = 0;
        for (int i = 0; i < n; i++, start += 2) {
            res ^= start;
        }
        return res;
    }
}
