#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    Solution()
    {
        vector<int> is_prime(101, 1), primes_vec;
        for (int i = 2; i <= 100; i++) {
            if (is_prime[i])
                primes_vec.emplace_back(i);
            for (size_t j = 0; j < primes_vec.size() && i * primes_vec[j] <= 100; j++) {
                is_prime[i * primes_vec[j]] = 0;
                if (i % primes_vec[j] == 0)
                    break;
            }
        }
        primes = unordered_set<int>(primes_vec.begin(), primes_vec.end());
    }

    int maximumPrimeDifference(vector<int>& nums)
    {
        int i = 0;
        while (!primes.contains(nums[i]))
            i++;

        int j = nums.size() - 1;
        while (!primes.contains(nums[j]))
            j--;

        return j - i;
    }

private:
    unordered_set<int> primes;
};
