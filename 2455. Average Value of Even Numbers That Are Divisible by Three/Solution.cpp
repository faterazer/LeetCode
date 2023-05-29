#include <vector>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums)
    {
        int sum = 0, cnt = 0;
        for (int x : nums) {
            if (x % 6 == 0) {
                sum += x;
                cnt++;
            }
        }
        return cnt ? sum / cnt : 0;
    }
};
