#include <vector>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums)
    {
        int element_sum = 0, digit_sum = 0;
        for (int x : nums) {
            element_sum += x;
            for (; x; x /= 10)
                digit_sum += x % 10;
        }
        return element_sum - digit_sum;
    }
};
