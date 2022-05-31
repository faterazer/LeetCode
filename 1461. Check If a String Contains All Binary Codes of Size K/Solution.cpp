#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k)
    {
        if (s.size() < (1 << k) + k - 1)
            return false;

        int n = stoi(s.substr(0, k), nullptr, 2);
        unordered_set<int> seen { n };
        int head_mask = ~(1 << (k - 1));
        for (int i = k; i < s.size(); ++i) {
            n = (n & head_mask) << 1 | (s[i] - '0');
            seen.emplace(n);
        }
        return seen.size() == (1 << k);
    }
};
