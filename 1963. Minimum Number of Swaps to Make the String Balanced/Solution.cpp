#include <string>
using namespace std;

class Solution {
public:
    int minSwaps(string s)
    {
        int cnt = 0;
        for (char c : s) {
            if (c == '[')
                ++cnt;
            else
                cnt = max(cnt - 1, 0);
        }
        return (cnt + 1) / 2;
    }
};
