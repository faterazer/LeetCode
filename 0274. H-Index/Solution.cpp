#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n = citations.size();
        vector<int> cnt(n + 1, 0);
        for (int c : citations)
            cnt[min(c, n)]++;

        int res = 0;
        for (int i = n; i >= 0; i--) {
            res += cnt[i];
            if (res >= i)
                return i;
        }
        return 0;
    }
};
