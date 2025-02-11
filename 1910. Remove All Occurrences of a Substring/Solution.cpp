#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part)
    {
        int n = part.size();
        vector<char> next(n);
        for (size_t i = 1, j = 0; i < part.size(); ++i) {
            while (j > 0 && part[i] != part[j])
                j = next[j - 1];
            if (part[i] == part[j])
                ++j;
            next[i] = j;
        }

        string ans;
        vector<int> next_cache{0};
        for (char c : s) {
            ans.push_back(c);
            int j = next_cache.back();
            while (j > 0 && c != part[j])
                j = next[j - 1];
            if (c == part[j])
                ++j;
            next_cache.push_back(j);
            if (j == part.size()) {
                ans.resize(ans.size() - part.size());
                next_cache.resize(next_cache.size() - part.size());
            }
        }
        return ans;
    }
};
