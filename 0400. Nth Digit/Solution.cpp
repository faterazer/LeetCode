#include <string>
using namespace std;

class Solution {
public:
    int findNthDigit(int n)
    {
        int digits = 1, nums = 9, base = 0;
        while (n / digits > nums) {
            n -= digits * nums;
            ++digits;
            nums *= 10;
            base = base * 10 + 9;
        }
        int res = base + n / digits;
        if (n % digits)
            res += 1;
        return to_string(res)[(n % digits - 1 + digits) % digits] - '0';
    }
};
