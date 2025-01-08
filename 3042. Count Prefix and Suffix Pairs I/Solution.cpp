#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words)
    {
        int ans = 0;
        for (size_t i = 0; i < words.size(); ++i)
            for (size_t j = i + 1; j < words.size(); ++j)
                ans += isPrefixAndSuffix(words[i], words[j]);
        return ans;
    }

private:
    bool isPrefixAndSuffix(const string &s, const string &t)
    {
        if (s.size() > t.size())
            return false;
        return t.find(s) == 0 && t.rfind(s) == t.size() - s.size();
    }
};
