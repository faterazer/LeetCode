#include <vector>
using namespace std;

class Solution
{
public:
    int numPrimeArrangements(int n)
    {
        // 线性筛（欧拉筛），计算出给定范围内的素数个数
        vector<int> buff(n + 1, 1);
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (buff[i])
                primes.emplace_back(i);
            for (size_t j = 0; j < primes.size() && primes[j] * i <= n; j++) {
                buff[primes[j] * i] = 0;
                if (i % primes[j] == 0)
                    break;
            }
        }
        long long res = 1;
        const int MOD = 1e9 + 7;
        int a = primes.size(), b = n - a;   // 给定范围内有 a 个素数，b 个合数，res = a! + b!
        for (int i = 2; i <= a; i++)
            res = (res * i) % MOD;
        for (int i = 2; i <= b; i++)
            res = (res * i) % MOD;
        return res;
    }
};
