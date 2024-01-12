#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2)
    {
        unordered_map<string, int> cnt1, cnt2;
        for (const string& w : words1)
            cnt1[w]++;
        for (const string& w : words2)
            cnt2[w]++;

        int res = 0;
        for (const auto& [k, v] : cnt1)
            if (v == 1 and cnt2[k] == 1)
                res++;
        return res;
    }
};
