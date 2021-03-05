#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        sort(arr2.begin(), arr2.end());
        int res = 0;
        for (const int &x : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), x);
            if (it != arr2.end() && abs(*it - x) <= d || it != arr2.begin() && abs(*(it -1) - x) <= d)
                continue;
            res++;
        }
        return res;
    }
};
