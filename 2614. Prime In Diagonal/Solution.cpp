#include <unordered_set>
#include <vector>
using namespace std;

vector<int> is_prime(4000001, 1), primes;
unordered_set<int> primes_set;
static int init = []() {
    for (size_t i = 2; i < is_prime.size(); ++i) {
        if (is_prime[i])
            primes.emplace_back(i);

        for (size_t j = 0; j < primes.size() && i * primes[j] < is_prime.size(); ++j) {
            is_prime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
    primes_set.reserve(primes.size());
    primes_set.insert(primes.begin(), primes.end());
    return 0;
}();

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums)
    {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (primes_set.contains(nums[i][i]))
                ans = max(ans, nums[i][i]);
            if (primes_set.contains(nums[i][n - 1 - i]))
                ans = max(ans, nums[i][n - 1 - i]);
        }
        return ans;
    }
};
