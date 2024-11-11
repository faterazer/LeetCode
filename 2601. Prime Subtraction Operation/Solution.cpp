#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    Solution()
    {
        vector<int> is_prime(1001, 1);
        for (size_t i = 2; i < is_prime.size(); ++i) {
            if (is_prime[i])
                primes.emplace_back(i);
            for (size_t j = 0; j < primes.size() && primes[j] * i < is_prime.size(); ++j) {
                is_prime[primes[j] * i] = 0;
                if (i % primes[j] == 0)
                    break;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums)
    {
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1])
                continue;
            auto it = upper_bound(primes.begin(), primes.end(), nums[i] - nums[i + 1]);
            if (it == primes.end() || *it >= nums[i])
                return false;
            nums[i] -= *it;
        }
        return true;
    }

private:
    vector<int> primes;
};
