#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot)
    {
        int i = 0, j = 0, k = 0;
        for (int x : nums) {
            if (x < pivot)
                ++j;
            else if (x == pivot)
                ++k;
        }
        k += j;
        vector<int> result(nums);
        for (int x : nums) {
            if (x < pivot)
                result[i++] = x;
            else if (x == pivot)
                result[j++] = x;
            else
                result[k++] = x;
        }
        return result;
    }
};
