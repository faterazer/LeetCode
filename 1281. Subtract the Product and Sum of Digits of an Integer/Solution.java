class Solution {
    public int subtractProductAndSum(int n) {
        int prod = 1, add = 0;
        for (; n > 0; n /= 10) {
            prod *= n % 10;
            add += n % 10;
        }
        return prod - add;
    }
}
