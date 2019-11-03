#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome_MK1(int);
    bool isPalindrome_MK2(int);
};

int main(int argc, char const *argv[])
{
    Solution s;

    int test1 = 121;
    cout << test1 << ":\t" << s.isPalindrome_MK2(test1) << endl;

    int test2 = -121;
    cout << test2 << ":\t" << s.isPalindrome_MK2(test2) << endl;

    int test3 = 10;
    cout << test3 << ":\t" << s.isPalindrome_MK2(test3) << endl;

    return 0;
}

bool Solution::isPalindrome_MK1(int x)
{
    long n = 0, hold = x;   // use larger type variable to avoid over-flowing
    if (x >= 0) {
        while(x) {
            n = n * 10 + x % 10;
            x /= 10;
        }
    }
    if (n == hold)
        return true;
    else
        return false;
}

bool Solution::isPalindrome_MK2(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertedNumber || x == revertedNumber / 10;
}