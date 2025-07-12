#include <functional>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable)
    {
        function<bool(int)> check = [&](int K) -> bool {
            unordered_set<int> removed(removable.begin(), removable.begin() + K);

            size_t j = 0;
            for (size_t i = 0; i < s.size() && j < p.size(); ++i)
                if (!removed.contains(i) && s[i] == p[j])
                    ++j;
            return j == p.size();
        };

        int lo = 0, hi = removable.size();
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1) + 1;
            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        return lo;
    }
};
