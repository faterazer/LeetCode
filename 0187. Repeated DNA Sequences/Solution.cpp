#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> res;
        if (s.size() < 10)
            return res;
        unordered_map<char, unsigned> mapper { { 'A', 0 }, { 'C', 1 }, { 'G', 2 }, { 'T', 3 } };
        unordered_map<unsigned, unsigned> cnt;
        unsigned mask = (1 << 20) - 1, x = 0;
        for (int i = 0; i < 9; ++i)
            x = (x << 2) | mapper[s[i]];
        for (size_t i = 9; i < s.size(); ++i) {
            x = ((x << 2) | mapper[s[i]]) & mask;
            if (++cnt[x] == 2)
                res.emplace_back(s.substr(i - 10 + 1, 10));
        }
        return res;
    }
};
