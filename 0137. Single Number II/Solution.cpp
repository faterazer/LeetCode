#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0, b = 0;
        for (int x : nums) {
            b = ~a & (b ^ x);
            a = ~b & (a ^ x);
        }
        return b;
    }
};
