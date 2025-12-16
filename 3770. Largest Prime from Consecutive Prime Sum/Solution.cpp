#include <algorithm>
#include <ranges>
#include <vector>
using namespace std;

constexpr int MX = 500001;
vector<int> is_prime(MX, 1);
vector<int> primes;
vector<int> candidates;

auto init = [] {
    for (int i = 2; i < MX; ++i) {
        if (is_prime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && i * primes[j] < MX; ++j) {
            is_prime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }

    long long prime_sum = 0;
    for (int p : primes) {
        prime_sum += p;
        if (prime_sum < is_prime.size() && is_prime[prime_sum])
            candidates.push_back(prime_sum);
    }
    return 0;
}();

class Solution {
public:
    int largestPrime(int n)
    {
        int idx = ranges::upper_bound(candidates, n) - candidates.begin();
        return idx > 0 ? candidates[idx - 1] : 0;
    }
};
