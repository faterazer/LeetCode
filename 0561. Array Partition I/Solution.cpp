#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    /**
     * Sort
     * Time complexity: O(nlgn)
     * Space complexity: O(1)
     */
    int arrayPairSum_MK1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0;
        for (size_t i = 0; i < nums.size(); i += 2)
            ret += nums[i];
        return ret;
    }

    /**
     * Hash
     * Time complexity: O(n)
     * Space complexity: O(n)
     */
    int arrayPairSum_MK2(vector<int> &nums)
    {
        vector<int> hash_table(20001, 0);
        for (const int &num : nums)
            hash_table[num + 10000]++;
        int d = 0, ret = 0;
        for (size_t i = 0; i < hash_table.size(); i++) {
            if (hash_table[i]) {
                ret += (hash_table[i] - d + 1) / 2 * (i - 10000);
                d = (hash_table[i] - d) % 2;
            }
        }
        return ret;
    }
};
