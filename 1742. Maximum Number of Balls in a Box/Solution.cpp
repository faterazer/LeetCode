#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {
        vector<int> count(46, 0);
        for (int i = lowLimit; i <= highLimit; i++) {
            int sum = 0;
            for (int j = i; j; j /= 10)
                sum += j % 10;
            count[sum]++;
        }
        return *max_element(count.begin(), count.end());
    }
};
