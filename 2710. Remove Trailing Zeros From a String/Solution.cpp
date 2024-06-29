#include <string>
using namespace std;

class Solution {
public:
    string removeTrailingZeros_MK1(string num)
    {
        while (num.back() == '0')
            num.pop_back();
        return num;
    }

    string removeTrailingZeros_MK2(string num)
    {
        num.erase(num.begin() + num.find_last_not_of('0') + 1, num.end());
        return num;
    }
};
