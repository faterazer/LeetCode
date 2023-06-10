#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> cnt(12, 0);
        for (const string &w : words)
            cnt[f(w)]++;
        for (int i = 9; i > 0; i--)
            cnt[i] += cnt[i + 1];

        vector<int> res;
        for (const string &q : queries)
            res.emplace_back(cnt[f(q) + 1]);
        return res;
    }

private:
    int f(const string &s)
    {
        char min_val = *min_element(s.begin(), s.end());
        return count(s.begin(), s.end(), min_val);
    }
};
