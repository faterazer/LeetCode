#include <algorithm>
#include <ranges>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        int ans = 0, prev = 0;
        for (const string& row : bank) {
            int cnt = ranges::count(row, '1');
            if (cnt) {
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};
