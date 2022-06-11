#include <string>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr_MK1(string s)
    {
        int ones = 0, zeros = 0;
        for (const char& c : s)
            zeros += c == '0';
        int res = zeros;
        for (const char& c : s) {
            if (c == '0')
                --zeros;
            else
                ++ones;
            res = min(res, ones + zeros);
        }
        return res;
    }

    int minFlipsMonoIncr_MK2(string s)
    {
        int cnt_ones = 0, cnt_flips = 0;
        for (const char& c : s) {
            if (c == '1')
                ++cnt_ones;
            else
                cnt_flips = min(cnt_flips + 1, cnt_ones);
        }
        return cnt_flips;
    }
};
