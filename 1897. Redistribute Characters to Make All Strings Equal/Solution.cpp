#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        unordered_map<char, int> cnter;
        for (const string &w : words)
            for (const char &c : w)
                cnter[c]++;
        return all_of(cnter.begin(), cnter.end(), [&](const auto &it) { return it.second % words.size() == 0; });
    }
};
