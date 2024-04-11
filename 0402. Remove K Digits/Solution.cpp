#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k)
    {
        if (k >= num.size())
            return "0";

        size_t i = 0;
        for (size_t j = 0; j < num.size(); ++j) {
            while (i > 0 && num[i - 1] > num[j] && k) {
                --i;
                --k;
            }
            if (i || num[j] != '0')
                num[i++] = num[j];
        }
        while (i > 0 && k--)
            --i;
        num.resize(i);
        return num.empty() ? "0" : num;
    }
};
