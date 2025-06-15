#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num)
    {
        string s = to_string(num);
        int mx = num;
        for (char c : s) {
            if (c != '9') {
                string t = s;
                ranges::replace(t, c, '9');
                mx = stoi(t);
                break;
            }
        }

        int mn = num;
        if (s[0] != '1') {
            string t = s;
            ranges::replace(t, s[0], '1');
            mn = stoi(t);
        } else {
            for (size_t i = 1; i < s.size(); ++i) {
                char c = s[i];
                if (c > '1') {
                    string t = s;
                    ranges::replace(t, c, '0');
                    mn = stoi(t);
                    break;
                }
            }
        }

        return mx - mn;
    }
};
