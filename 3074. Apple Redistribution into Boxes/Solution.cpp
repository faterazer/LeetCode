#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int apple_cnt = reduce(apple.begin(), apple.end());
        ranges::sort(capacity, greater{});
        int i = 0;
        while (apple_cnt > 0)
            apple_cnt -= capacity[i++];
        return i;
    }
};
