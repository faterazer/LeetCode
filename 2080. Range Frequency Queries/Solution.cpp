#include <algorithm>
#include <ranges>
#include <unordered_map>
#include <vector>
using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr)
    {
        for (size_t i = 0; i < arr.size(); ++i)
            value2ids[arr[i]].emplace_back(i);
    }

    int query(int left, int right, int value)
    {
        return ranges::upper_bound(value2ids[value], right) - ranges::lower_bound(value2ids[value], left);
    }

private:
    unordered_map<int, vector<int>> value2ids;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
