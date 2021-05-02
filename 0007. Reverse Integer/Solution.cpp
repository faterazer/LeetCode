#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long n = 0;
        do {
            n = n * 10 + x % 10;
        } while (x /= 10);
        if (n <= INT32_MAX && n >= INT32_MIN)
            return static_cast<int>(n);
        else
            return 0;
    }
};
