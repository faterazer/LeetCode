#include <cmath>

class Solution
{
public:
    /**
     * Time complexity: O(√clgc).
     * Space complexity: O(1).
     */
    bool judgeSquareSum_MK1(int c)
    {
        int n = sqrt(c);
        for (int i = 0; i <= n; i++) {
            int j = sqrt(c - (i * i));
            if (i * i + j * j == c)
                return true;
        }
        return false;
    }

    /**
     * Fermat Theorem: Any positive number n is expressible as a sum of two squares if 
     * and only if the prime factorization of n, every prime of the form (4k+3) occurs
     * even number of times.
     * Time complexity: O(√clgc).
     * Space complexity: O(1).
     */
    bool judgeSquareSum_MK2(int c)
    {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    c /= i;
                    count++;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};
