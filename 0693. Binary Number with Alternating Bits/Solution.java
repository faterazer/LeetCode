class Solution {
    public boolean hasAlternatingBits(int n) {
        return (n & (n >> 1)) == 0 && (n & (n >> 2)) == (n >> 2);
    }
}
