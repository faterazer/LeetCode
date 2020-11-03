#include <string>
using namespace std;

class Solution
{
public:
    int maxPower(string s)
    {
        int ret = 1, power = 1;
        for (size_t i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                power++;
            else {
                ret = max(power, ret);
                power = 1;
            }
        }
        return max(ret, power);
    }
};
