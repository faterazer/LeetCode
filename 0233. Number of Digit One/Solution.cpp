#include <vector>
using namespace std;

class Solution {
public:
    int countDigitOne(int n)
    {
        long long power = 1, tail = 0;
        int res = 0;
        for (; n; n /= 10) {
            tail = n % 10 * power + tail;
            res += n / 10 * power + min(max(tail - power + 1, 0LL), power);
            power *= 10;
        }
        return res;
    }
};
