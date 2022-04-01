#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr)
    {
        map<int, int> counter;
        for (const int &e : arr)
            ++counter[e];
        for (auto &it : counter) {
            if (!it.second)
                continue;
            int want = it.first < 0 ? it.first / 2 : it.first * 2;
            if ((it.first < 0 && it.first % 2) || !counter.count(want) || counter[want] < it.second)
                return false;
            counter[want] -= it.second;
        }
        return true;
    }
};
