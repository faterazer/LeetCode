#include <climits>
#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int);
};

int main(int argc, char const *argv[])
{
    Solution s;
    int test1 = 123;
    cout << test1 << ":\t" << s.reverse(test1) << endl;
    int test2 = -123;
    cout << test2 << ":\t" << s.reverse(test2) << endl;
    int test3 = 120;
    cout << test3 << ":\t" << s.reverse(test3) << endl;
    int test4 = 1534236469;
    cout << test4 << ":\t" << s.reverse(test4) << endl;
    return 0;
}

int Solution::reverse(int x)
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