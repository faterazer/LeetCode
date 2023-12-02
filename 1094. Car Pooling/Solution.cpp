#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int diff[1001] = { 0 };
        for (const vector<int>& trip : trips) {
            diff[trip[1]] += trip[0];
            diff[trip[2]] -= trip[0];
        }

        int num_passengers = 0;
        for (const int x : diff) {
            num_passengers += x;
            if (num_passengers > capacity)
                return false;
        }
        return true;
    }
};
