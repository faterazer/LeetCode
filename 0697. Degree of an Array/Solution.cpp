#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

typedef struct record
{
    record() = default;
    record(int d, int b) : degree(d), begin(b) {}
    int degree = 0;
    int begin = 0;
} record;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, record> hash_table;
        int min_len = 1, max_deg = 0, size = nums.size();
        for (int i = 0; i < size; i++) {
            if (hash_table.count(nums[i])) {
                hash_table[nums[i]].degree += 1;
                if (hash_table[nums[i]].degree > max_deg) {
                    max_deg = hash_table[nums[i]].degree;
                    min_len = i - hash_table[nums[i]].begin + 1;
                }
                else if (hash_table[nums[i]].degree == max_deg)
                    min_len = min(min_len, i - hash_table[nums[i]].begin + 1);
            }
            else
                hash_table[nums[i]] = record(1, i);
        }
        return min_len;
    }
};
