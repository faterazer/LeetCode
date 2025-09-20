#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minTime(string s, vector<int>& order, int k)
    {
        int n = s.size();
        long long cnt = 1LL * n * (n + 1) / 2;
        if (cnt < k)
            return -1;

        vector<int> prev(n), next(n);
        iota(prev.begin(), prev.end(), -1);
        iota(next.begin(), next.end(), 1);
        for (int t = n - 1; t >= 0; --t) {
            int i = order[t];
            int l = prev[i], r = next[i];
            cnt -= 1LL * (i - l) * (r - i);
            if (cnt < k)
                return t;
            if (l >= 0)
                next[l] = r;
            if (r < n)
                prev[r] = l;
        }
        return -1;
    }
};
