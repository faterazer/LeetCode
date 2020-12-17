#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int l = 0, r = arr.size() - 1, mid;
        while (l < r) {
            mid = l + ((r - l) >> 1);
            if (arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
