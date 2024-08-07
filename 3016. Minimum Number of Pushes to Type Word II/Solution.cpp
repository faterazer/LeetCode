#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word)
    {
        int cnt[26] = { 0 };
        for (char c : word)
            ++cnt[c - 'a'];

        ranges::sort(cnt, greater());
        int res = 0;
        for (int i = 0; i < 26; i++)
            res += cnt[i] * (i / 8 + 1);
        return res;
    }
};
