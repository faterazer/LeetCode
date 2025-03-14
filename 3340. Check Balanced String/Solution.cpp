#include <string>
using namespace std;

class Solution {
public:
    bool isBalanced(string num)
    {
        int s = 0;
        for (size_t i = 0; i < num.size(); ++i) {
            if (i & 1)
                s -= num[i] - '0';
            else
                s += num[i] - '0';
        }
        return s == 0;
    }
};
