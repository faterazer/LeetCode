#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int splitNum(int num)
    {
        vector<int> digits;
        for (; num; num /= 10)
            digits.emplace_back(num % 10);
        sort(digits.begin(), digits.end());

        int a = 0, b = 0;
        for (size_t i = 0; i < digits.size(); i++) {
            if ((i & 1) == 0)
                a = a * 10 + digits[i];
            else
                b = b * 10 + digits[i];
        }
        return a + b;
    }
};
