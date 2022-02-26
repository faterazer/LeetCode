#include <vector>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums)
    {
        int res = -1, minimum = INT_MAX;
        for (const int &e : nums) {
            if (e > minimum)
                res = max(res, e - minimum);
            else
                minimum = e;
        }
        return res;    
    }
};
