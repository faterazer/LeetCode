#include <algorithm>
#include <bit>
#include <string>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.size(), m = bit_width(static_cast<unsigned>(k));
        if (n < m)
            return n;
        int suf_val = stoi(s.substr(n - m), nullptr, 2);
        int ans = suf_val <= k ? m : m - 1;
        return ans + count(s.begin(), s.end() - m, '0');
    }
};
