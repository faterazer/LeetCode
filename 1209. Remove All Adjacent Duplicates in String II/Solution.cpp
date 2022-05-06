#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>> buff;
        for (const char &c : s) {
            if (buff.empty() || buff.back().first != c)
                buff.emplace_back(c, 1);
            else
                buff.back().second += 1;
            if (buff.back().second == k)
                buff.pop_back();
        }
        string res;
        for (const pair<char, int> &p : buff)
            res += string(p.second, p.first);
        return res;
    }
};
