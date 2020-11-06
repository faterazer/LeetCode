#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const int &left, const int &right)
{
    int l = left, r = right;
    int lbits = 0, rbits = 0;
    for (; l; l &= l - 1)
        lbits++;
    for (; r; r &= r - 1)
        rbits++;
    if (lbits != rbits)
        return lbits < rbits;
    return left < right;
}

class Solution
{
public:
    vector<int> sortByBits(vector<int> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
