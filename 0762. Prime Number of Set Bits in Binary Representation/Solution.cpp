#include <bitset>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int countPrimeSetBits(int L, int R)
    {
        int cnt = 0;
        for (int i = L; i <= R; i++)
                cnt += 665772 >> bitset<32>(i).count() & 1; // 665772 的二进制表示上，所有的质数位都是 1
        return cnt;
    }
};
