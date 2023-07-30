#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordPatternMatch(string pattern, string s)
    {
        unordered_map<char, string> table;
        unordered_set<string> appeared;
        return helper(pattern, 0, s, 0, table, appeared);
    }

private:
    bool helper(const string& pattern, size_t pi, const string& s, size_t si, unordered_map<char, string>& table, unordered_set<string>& appeared)
    {
        if (pi == pattern.size() && si == s.size())
            return true;
        if (pi == pattern.size() || si == s.size())
            return false;

        if (table.count(pattern[pi])) {
            char pc = pattern[pi];
            string ps = table[pc];
            if (startswith(s, si, ps))
                return helper(pattern, pi + 1, s, si + ps.size(), table, appeared);
            else
                return false;
        }

        char pc = pattern[pi];
        string ps;
        for (; si < s.size(); si++) {
            ps.push_back(s[si]);
            if (appeared.count(ps))
                continue;
            table[pc] = ps;
            appeared.emplace(ps);
            if (helper(pattern, pi + 1, s, si + 1, table, appeared))
                return true;
            appeared.erase(ps);
            table.erase(pc);
        }
        return false;
    }

    bool startswith(const string& s, size_t si, const string& prefix)
    {
        for (size_t i = 0; i < prefix.size() && si < s.size(); i++, si++)
            if (s[si] != prefix[i])
                return false;
        return true;
    }
};
