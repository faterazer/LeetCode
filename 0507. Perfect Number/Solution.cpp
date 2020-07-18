#include <cmath>

class Solution
{
public:
    bool checkPerfectNumber_MK1(int num)
    {
        if (num <= 1)
            return false;

        int sum = 1;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0)
                sum += i + num / i;
        return sum == num;
    }

    /** 
     * Euclid-Euler Theorem
     * 1. 目前还没有找到奇完全数，是否有奇完全数还是一个猜想
     * 2. Euclid-Euler Theorem 证明每一个偶完全数都可以写成
     *    2^{p-1}(2^p-1) 的形式，其中 p 为素数。
     * 3. 根据数值范围，验证前几个素数就足够了
     */
    bool checkPerfectNumber_MK2(int num)
    {
        int primes[] = {2, 3, 5, 7, 13};    // 更大的素数就溢出了
        for (const int &prime : primes) {
            int t = pow(2, prime - 1) * (pow(2, prime) - 1);
            if (t == num)
                return true;
        }
        return false;
    }
};
