#include <cmath>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1) - 1e-5);
    }
};
