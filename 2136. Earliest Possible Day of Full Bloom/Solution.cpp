#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int earliestFullBloom_MK1(vector<int>& plantTime, vector<int>& growTime)
    {
        int n = plantTime.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](const int& left, const int& right) {
            return growTime[left] < growTime[right];
        });
        int res = 0;
        for (const int& i : idxs)
            res = max(res, growTime[i]) + plantTime[i];
        return res;
    }

    int earliestFullBloom_MK2(vector<int>& plantTime, vector<int>& growTime)
    {
        int n = plantTime.size();
        vector<int> idxs(n);
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&](const int& left, const int& right) {
            return growTime[left] > growTime[right];
        });
        int res = 0, ed = 0;
        for (const int& i : idxs) {
            ed += plantTime[i];
            res = max(res, ed + growTime[i]);
        }
        return res;
    }
};
