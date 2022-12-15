#include <string>
using namespace std;

class Solution {
public:
    int getLucky(string s, int k)
    {
        int res = 0;
        for (const char& c : s)
            res += digitSum(c - 'a' + 1);
        for (int i = 2; i <= k; i++)
            res = digitSum(res);
        return res;
    }

private:
    int digitSum(int x)
    {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }
};
