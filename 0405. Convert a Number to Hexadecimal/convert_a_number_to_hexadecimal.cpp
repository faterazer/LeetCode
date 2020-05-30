#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string toHex(int num);
private:
    char dec2hex[17] = "0123456789abcdef";
};

string Solution::toHex(int num)
{
    if (!num)
        return "0";

    string ret;
    for (unsigned n = num; n; n >>= 4)
        ret.push_back(dec2hex[n & 15]);
    reverse(ret.begin(), ret.end());
    return ret;
}
