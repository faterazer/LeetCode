#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words)
    {
        int res = 0;
        unordered_map<string, int> cnt;
        for (const string& w : words) {
            res += cnt[w];
            cnt[string(w.rbegin(), w.rend())]++;
        }
        return res;
    }
};
