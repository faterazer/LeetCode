class Solution {
    public int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        return ~N & (Integer.highestOneBit(N) - 1);
    }
}
