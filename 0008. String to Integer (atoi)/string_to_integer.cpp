#include <cctype>
#include <numeric>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string str);
};

int Solution::myAtoi(string str)
{
    size_t i = 0;
    int sign = 1;
    long long ans = 0;
    while (i < str.size() && str[i] == ' ')
        i++;
    if (i < str.size() && (str[i] == '+' || str[i] == '-'))
        sign = str[i++] == '-' ? -1 : 1;
    for (; i < str.size() && isdigit(str[i]); i++) {
        ans = ans * 10 + str[i] - '0';
        if (ans * sign > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        if (ans * sign < numeric_limits<int>::min())
            return numeric_limits<int>::min();
    }
    return ans * sign;
}
