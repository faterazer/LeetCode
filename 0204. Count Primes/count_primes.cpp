#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int countPrimes(int n);
};

int Solution::countPrimes(int n)
{
    vector<bool> is_prime(n, true);
    for (size_t i = 2; i * i < is_prime.size(); i++) {
        if (is_prime[i]) {
            for (size_t j = i * i; j < is_prime.size(); j += i)
                is_prime[j] = false;
        }
    }
    
    int count = 0;
    for (size_t i = 2; i < is_prime.size(); i++)
        if (is_prime[i])
            count++;
    return count;
}
