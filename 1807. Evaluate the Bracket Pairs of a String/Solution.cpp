#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        unordered_map<string, string> mapper;
        for (const vector<string>& k : knowledge)
            mapper[k[0]] = k[1];

        string res;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                int j = s.find(')', i + 1);
                auto it = mapper.find(s.substr(i + 1, j - i - 1));
                res += it == mapper.end() ? "?" : it->second;
                i = j;
            } else
                res.push_back(s[i]);
        }
        return res;
    }
};
