#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int gap = arr.size() / 4;
        for (const int &i : {gap, gap * 2, gap * 3}) {
            auto p = equal_range(arr.begin(), arr.end(), arr[i]);
            if (p.second - p.first > gap)
                return arr[i];
        }
        return 0;
    }
};
