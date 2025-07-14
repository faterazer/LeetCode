#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> ans;
        for (int i = 1; i <= 9; ++i) {
            int x = i;
            for (int j = i + 1; j <= 9; ++j) {
                x = x * 10 + j;
                if (x >= low && x <= high)
                    ans.emplace_back(x);
                else if (x > high)
                    break;
            }
        }
        ranges::sort(ans);
        return ans;
    }
};
