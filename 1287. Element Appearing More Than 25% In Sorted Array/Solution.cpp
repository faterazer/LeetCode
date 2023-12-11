#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr)
    {
        int n = arr.size();
        for (const int& i : { n / 4, n * 2 / 4, n * 3 / 4 }) {
            auto p = equal_range(arr.begin(), arr.end(), arr[i]);
            if (4 * distance(p.first, p.second) > n)
                return arr[i];
        }
        return 0;
    }
};
