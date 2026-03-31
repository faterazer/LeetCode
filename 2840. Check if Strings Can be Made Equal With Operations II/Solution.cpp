#include <algorithm>
#include <array>
#include <functional>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2)
    {
        array<int, 26> cnt { 0 };
        int n = s1.size();
        for (int beg = 0; beg < 2; ++beg) {
            for (int i = beg; i < n; i += 2) {
                ++cnt[s1[i] - 'a'];
                --cnt[s2[i] - 'a'];
            }
            if (ranges::any_of(cnt, identity{}))
                return false;
        }
        return true;
    }
};
