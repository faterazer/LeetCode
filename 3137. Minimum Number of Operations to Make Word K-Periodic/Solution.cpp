#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        unordered_map<string, int> cnt;
        int max_freq = 0;
        for (size_t i = 0; i < word.size(); i += k)
            max_freq = max(max_freq, ++cnt[word.substr(i, k)]);
        return word.size() / k - max_freq;
    }
};
