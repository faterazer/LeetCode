#include <vector>
using namespace std;

class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int cnt = 0, goal = (k - 1) * m;
        for (size_t i = 0; i + m < arr.size(); i++) {
            if (arr[i] == arr[i + m]) {
                if (++cnt == goal)
                    return true;
            }
            else
                cnt = 0;
        }
        return false;
    }
};
