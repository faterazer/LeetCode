#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> cnt;
        for (const char& c : s)
            ++cnt[c];

        vector<pair<char, int>> buff;
        for (const auto& it : cnt)
            buff.emplace_back(it);
        sort(buff.begin(), buff.end(), [](const pair<char, int>& left, const pair<char, int>& right) {
            return left.second > right.second;
        });

        string res;
        for (const pair<char, int>& p : buff) {
            res += string(p.second, p.first);
        }
        return res;
    }
};
