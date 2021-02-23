#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int maxE = -1, tmp;
        for (auto it = arr.rbegin(); it != arr.rend(); it++) {
            tmp = *it;
            *it = maxE;
            maxE = max(*it, tmp);
        }
        return arr;
    }
};
