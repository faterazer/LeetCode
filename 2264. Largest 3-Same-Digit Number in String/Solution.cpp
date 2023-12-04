#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num)
    {
        string res;
        for (size_t i = 2; i < num.size(); i++)
            if (num[i - 2] == num[i - 1] && num[i - 2] == num[i] && (res.empty() || num[i] > res[0]))
                res = string(3, num[i]);
        return res;
    }
};
