#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    // 埃氏筛
    int countPrimes_MK1(int n)
    {
        int cnt = 0;
        vector<int> is_prime(n, 1);
        for (size_t i = 2; i < is_prime.size(); i++) {
            if (is_prime[i]) {
                cnt++;
                for (size_t j = i * i; j < is_prime.size(); j += i)
                    is_prime[j] = 0;
            }
        }
        return cnt;
    }

    // 线性筛
    int countPrimes_MK2(int n)
    {
        vector<int> is_prime(n, 1);
        vector<int> primes;
        for (int i = 2; i < n; i++) {
            if (is_prime[i])
                primes.emplace_back(i);
            for (size_t j = 0; j < primes.size() && i * primes[j] < n; j++) {
                is_prime[i * primes[j]] = 0;
                if (i % primes[j] == 0)
                    break;
            }
        }
        return primes.size();
    }
};
