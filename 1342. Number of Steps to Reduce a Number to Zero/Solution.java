class Solution {
    public int numberOfSteps (int num) {
        int res = 0;
        while (num != 0) {
            if (num % 2 == 0) {
                num >>= 1;
            } else {
                num -= 1;
            }
            res++;
        }
        return res;
    }
}
