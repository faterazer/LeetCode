#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k)
    {
        int n = s.size(), i = 0;
        array<int, 3> cnt = { 0 };
        for (; i < n && ranges::min(cnt) < k; ++i)
            ++cnt[s[i] - 'a'];
        if (ranges::min(cnt) < k)
            return -1;

        int res = i--;
        for (int j = n - 1; i >= 0; --j) {
            ++cnt[s[j] - 'a'];
            while (i >= 0 && cnt[s[i] - 'a'] > k)
                --cnt[s[i--] - 'a'];
            res = min(res, i + 1 + n - j);
        }
        return res;
    }
};
