#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u' };
        vector<int> pre_sum(words.size() + 1, 0);
        for (size_t i = 1; i < pre_sum.size(); i++)
            pre_sum[i] = pre_sum[i - 1] + (vowels.count(words[i - 1][0]) && vowels.count(words[i - 1].back()));

        vector<int> res;
        for (const vector<int>& q : queries)
            res.emplace_back(pre_sum[q[1] + 1] - pre_sum[q[0]]);
        return res;
    }
};
