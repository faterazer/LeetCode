#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ret;
        for (int i = left; i <= right; i++)
            if (isSelfDividing(i))
                ret.emplace_back(i);
        return ret;
    }

private:
    bool isSelfDividing(int n)
    {
        for (int i = n; i; i /= 10) {
            int digit = i % 10;
            if (!digit || n % digit)
                return false;
        }
        return true;
    }
};
