#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit)
    {
        int n = values.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return values[i] > values[j];
        });

        unordered_map<int, int> cnt;
        int res = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (++cnt[labels[ids[i]]] > useLimit)
                continue;
            res += values[ids[i]];
            if (++c == numWanted)
                break;
        }
        return res;
    }
};
