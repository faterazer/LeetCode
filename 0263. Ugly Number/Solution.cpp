#include <vector>
using namespace std;

class Solution
{
public:
    bool isUgly(int num)
    {
        if (num <= 0)
            return false;
        vector<int> factors{2, 3, 5};
        for (const int factor : factors)
            while (num % factor == 0)
                num /= factor;
        return num == 1;
    }
};
