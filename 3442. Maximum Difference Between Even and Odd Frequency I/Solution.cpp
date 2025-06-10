#include <string>
using namespace std;

class Solution {
public:
    int maxDifference(string s)
    {
        int cnt[26] = { 0 };
        for (char c : s)
            ++cnt[c - 'a'];
        int max_odd = 0, min_even = s.size();
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == 0)
                continue;
            else if (cnt[i] & 1)
                max_odd = max(max_odd, cnt[i]);
            else
                min_even = min(min_even, cnt[i]);
        }
        return max_odd - min_even;
    }
};
