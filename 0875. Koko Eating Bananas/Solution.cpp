#include <vector>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l = 1, r = *max_element(piles.begin(), piles.end()), m;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            int hours = 0;
            for (const int& e : piles)
                hours += 1 + (e - 1) / m;
            if (hours > h)
                l = m + 1;
            else
                r = m - 1;
        }
        return l;
    }
};
