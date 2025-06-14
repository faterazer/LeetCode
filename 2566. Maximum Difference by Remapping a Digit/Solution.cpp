#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        int mx = num;
        for (char c : s) {
            if (c != '9') {
                string tmp = s;
                ranges::replace(tmp, c, '9');
                mx = stoi(tmp);
                break;
            }
        }

        char c0 = s[0];
        ranges::replace(s, c0, '0');
        int mn = stoi(s);
        return mx - mn;
    }
};
