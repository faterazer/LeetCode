#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings)
    {
        unordered_map<string, vector<string>> table;
        for (const string &s : strings) {
            int offset = s[0] - 'a';
            string key;
            for (char c : s)
                key.push_back((c - 'a' - offset + 26) % 26 + 'a');
            table[key].emplace_back(s);
        }

        vector<vector<string>> res;
        for (const auto &[_, arr] : table)
            res.emplace_back(arr);
        return res;
    }
};
