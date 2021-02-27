#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        int a = 0, b = 0, power = 1, digit;
        for (; n; n /= 10, power *= 10) {
            if (n % 10 > 1 || n < 10)
                digit = n % 10;
            else {
                digit = 10 + n % 10;
                n -= 10;
            }
            a += digit / 2 * power;
            b += (digit + 1) / 2 * power;
        }
        return {a, b};
    }
};
