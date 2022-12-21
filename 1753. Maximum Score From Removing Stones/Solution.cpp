#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c)
    {
        int sum = a + b + c, max_val = max({ a, b, c });
        return min(sum - max_val, sum / 2);
    }
};
