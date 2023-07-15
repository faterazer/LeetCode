#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generatePalindromes(string s)
    {
        unordered_map<char, int> cnt;
        for (char c : s)
            cnt[c]++;

        vector<string> res;
        int odds = 0;
        for (const auto& [_, v] : cnt)
            odds += v & 1;
        if (odds > 1)
            return res;

        s.clear();
        string odd;
        for (const auto& [k, v] : cnt) {
            s += string(v >> 1, k);
            if (v & 1)
                odd = k;
        }
        sort(s.begin(), s.end());
        do {
            res.emplace_back(s + odd + string(s.rbegin(), s.rend()));
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
};
