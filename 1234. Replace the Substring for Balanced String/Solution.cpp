#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int balancedString(string s)
    {
        unordered_map<char, int> cnt;
        int n = s.size(), res = n, i = 0, limit = n / 4;
        for (const char& c : s)
            cnt[c]++;
        if (cnt['Q'] == limit && cnt['W'] == limit && cnt['E'] == limit && cnt['R'] == limit)
            return 0;
        for (int j = 0; j < n; j++) {
            cnt[s[j]]--;
            while (cnt['Q'] <= limit && cnt['W'] <= limit && cnt['E'] <= limit && cnt['R'] <= limit) {
                res = min(res, j - i + 1);
                cnt[s[i++]]++;
            }
        }
        return res;
    }
};
