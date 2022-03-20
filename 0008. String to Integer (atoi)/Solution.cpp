#include <cctype>
#include <numeric>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str)
    {
        int res = 0, sign = 1, i = 0;
        while (i < str.size() && isspace(str[i]))
            i += 1;
        if (i < str.size() && (str[i] == '+' || str[i] == '-'))
            sign = str[i++] == '-' ? -1 : 1;
        while (i < str.size() && isdigit(str[i])) {
            int d = str[i++] - '0';
            if (sign == 1 && (INT_MAX / 10 < res || INT_MAX - d < res * 10))
                return INT_MAX;
            else if (sign == -1 && (INT_MIN / 10 > res || INT_MIN + d > res * 10))
                return INT_MIN;
            res = res * 10 + d * sign;
        }
        return res;
    }
};
