#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    Solution()
    {
        for (int i = 0; i < 32; ++i) {
            string s = to_string(1 << i);
            sort(s.begin(), s.end());
            nums.emplace(s);
        }
    }

    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        return nums.count(s);
    }

private:
    unordered_set<string> nums;
};
