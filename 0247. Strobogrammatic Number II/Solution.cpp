#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findStrobogrammatic(int n, bool flag = true)
    {
        if (n == 0)
            return { "" };
        if (n == 1)
            return { "0", "1", "8" };

        vector<string> candidates { "11", "69", "88", "96", "00" };
        vector<string> substr = findStrobogrammatic(n - 2, false), res;
        for (const string& cand : candidates) {
            if (flag && cand == "00")
                break;
            for (const string& s : substr)
                res.emplace_back(cand[0] + s + cand[1]);
        }
        return res;
    }
};
