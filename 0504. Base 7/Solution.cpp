#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string convertToBase7(int num)
    {
        string ret;
        bool is_negative = num < 0;
        do {
            ret += abs(num % 7) + '0';
            num /= 7;
        } while (num);
        if (is_negative)
            ret += '-';
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
