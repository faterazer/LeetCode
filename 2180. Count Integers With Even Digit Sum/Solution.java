class Solution {
    public int countEven(int num) {
        int temp = num, sum = 0;
        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }
        int res = num / 10 * 5 - 1;
        if (sum % 2 == 1) {
            return res + (num % 10 + 1) / 2;
        } else {
            return res + num % 10 / 2 + 1;
        }
    }
}
