#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int idx = key2idx[ruleKey];
        return count_if(items.begin(), items.end(), [&](const vector<string> &x) { return x[idx] == ruleValue; });
    }

private:
    static unordered_map<string, int> key2idx;
};

unordered_map<string, int> Solution::key2idx{{"type", 0}, {"color", 1}, {"name", 2}};
