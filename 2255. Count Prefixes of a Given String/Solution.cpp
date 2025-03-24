#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s)
    {
        return ranges::count_if(words, [&](const string& word) { return s.starts_with(word); });
    }
};
