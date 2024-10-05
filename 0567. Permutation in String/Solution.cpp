#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int cnt[26] = { 0 }, m = s1.size();
        for (char c : s1)
            --cnt[c - 'a'];

        int i = 0, n = s2.size();
        for (int j = 0; j < n; ++j) {
            int idx = s2[j] - 'a';
            ++cnt[idx];
            while (cnt[idx] > 0)
                --cnt[s2[i++] - 'a'];
            if (j - i + 1 == m)
                return true;
        }
        return false;
    }
};
