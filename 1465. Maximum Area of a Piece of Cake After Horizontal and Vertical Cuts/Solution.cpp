#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        const int P = 1000000007;
        return static_cast<long long>(getMax(h, horizontalCuts)) * getMax(w, verticalCuts) % P;
    }

private:
    int getMax(int n, vector<int> &cuts) {
        sort(cuts.begin(), cuts.end());
        int res = max(cuts[0], n - cuts.back());
        for (size_t i = 1; i < cuts.size(); ++i)
            res = max(res, cuts[i] - cuts[i - 1]);
        return res;
    }
};
