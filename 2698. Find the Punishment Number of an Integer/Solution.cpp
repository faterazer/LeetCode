class Solution {
public:
    int punishmentNumber(int n)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            if (is_punishment_number(i * i, i))
                res += i * i;
        return res;
    }

private:
    bool is_punishment_number(int x, int need)
    {
        if (x == need)
            return true;
        int cur = 0, power = 1;
        while (x) {
            cur = x % 10 * power + cur;
            x /= 10;
            power *= 10;
            if (is_punishment_number(x, need - cur))
                return true;
        }
        return false;
    }
};
