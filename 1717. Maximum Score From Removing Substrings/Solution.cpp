#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y) {
            swap(x, y);
            ranges::reverse(s);
        }

        int ans = 0, a_cnt = 0, b_cnt = 0;
        for (char c : s) {
            if (c == 'a')
                ++a_cnt;
            else if (c == 'b') {
                if (a_cnt) {
                    --a_cnt;
                    ans += x;
                } else
                    ++b_cnt;
            } else {
                ans += min(a_cnt, b_cnt) * y;
                a_cnt = b_cnt = 0;
            }
        }
        return ans + min(a_cnt, b_cnt) * y;
    }
};
