#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        if (chalk[0] > k)
            return 0;
        for (size_t i = 1; i < chalk.size(); i++) {
            if (chalk[i - 1] > k - chalk[i])
                return i;
            chalk[i] += chalk[i - 1];
        }
        k %= chalk.back();
        return ranges::upper_bound(chalk, k) - chalk.begin();
    }
};
