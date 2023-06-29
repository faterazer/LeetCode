#include <string>
using namespace std;

class Solution {
public:
    int strobogrammaticInRange(string low, string high)
    {
        int res = 0;
        helper(low, high, high.size(), true, res);
        helper(low, high, high.size() - 1, true, res);
        return res;
    }

private:
    vector<string> helper(const string& low, const string& high, int n, bool flag, int& res)
    {
        if (n == 0)
            return { "" };
        if (n == 1) {
            res += check(low, high, "0") + check(low, high, "1") + check(low, high, "8");
            return { "0", "1", "8" };
        }

        vector<string> candidates { "11", "69", "88", "96", "00" };
        vector<string> substr = helper(low, high, n - 2, false, res);
        vector<string> buff;
        for (const string& cand : candidates) {
            if (flag && cand == "00")
                break;
            for (const string& s : substr) {
                buff.emplace_back(cand[0] + s + cand[1]);
                res += check(low, high, buff.back()) && buff.back()[0] != '0';
            }
        }
        return buff;
    }

    bool check(const string& low, const string& high, const string& s)
    {
        if (s.size() > low.size() && s.size() < high.size())
            return true;
        if (s.size() == low.size() && s.size() == high.size())
            return s >= low && s <= high;
        if (s.size() == low.size())
            return s >= low;
        if (s.size() == high.size())
            return s <= high;
        return false;
    }
};
