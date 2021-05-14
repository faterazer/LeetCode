#include <vector>
using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int mx = 0, cnt = 0, k;
        for (const vector<int> &rect : rectangles) {
            k = min(rect[0], rect[1]);
            if (mx < k) {
                mx = k;
                cnt = 1;
            }
            else if (mx == k)
                cnt++;
        }
        return cnt;
    }
};
