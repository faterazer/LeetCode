#include <array>
#include <string>
using namespace std;

class Solution {
public:
    int longestBalanced(string s)
    {
        int n = s.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            array<int, 26> cnt {};
            int mx = 0, kinds = 0;
            for (int j = i; j < n; ++j) {
                int c = s[j] - 'a';
                if (cnt[c] == 0)
                    ++kinds;
                mx = max(mx, ++cnt[c]);
                if (mx * kinds == j - i + 1)
                    result = max(result, j - i + 1);
            }
            if (n - i + 1 <= result)
                break;
        }
        return result;
    }
};
