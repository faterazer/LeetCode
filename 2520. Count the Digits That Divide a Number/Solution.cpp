class Solution {
public:
    int countDigits(int num)
    {
        int res = 0;
        for (int x = num; x; x /= 10)
            if (num % (x % 10) == 0)
                ++res;
        return res;
    }
};
