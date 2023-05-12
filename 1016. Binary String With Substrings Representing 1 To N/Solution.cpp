#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n)
    {
        if (n == 1)
            return s.find('1') != string::npos;

        int m = s.size(), k = -1;
        for (int x = n; x; x >>= 1)
            k++;
        if (m < max(k + n - (1 << k) + 1, (1 << (k - 1)) + k - 1))
            return false;

        auto check = [&](int k, int lower, int upper) -> bool {
            if (lower > upper)
                return true;
            unordered_set<int> seen;
            int mask = (1 << (k - 1)) - 1;
            int x = stoi(s.substr(0, k - 1), nullptr, 2);
            for (int i = k - 1; i < m; i++) {
                x = ((x & mask) << 1) | (s[i] - '0');
                if (lower <= x && x <= upper)
                    seen.emplace(x);
            }
            return seen.size() == upper - lower + 1;
        };

        return check(k, n / 2 + 1, (1 << k) - 1) && check(k + 1, 1 << k, n);
    }
};
