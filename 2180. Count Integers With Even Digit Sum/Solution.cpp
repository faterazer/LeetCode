class Solution {
public:
    int countEven(int num)
    {
        int res = num / 10 * 5 - 1, tmp = num;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        if (sum & 1)
            res += (tmp % 10 + 1) / 2;
        else
            res += tmp % 10 / 2 + 1;
        return res;
    }
};
