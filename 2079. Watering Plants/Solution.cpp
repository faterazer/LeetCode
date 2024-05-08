#include <vector>
using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity)
    {
        int res = plants.size(), water = capacity;
        for (size_t i = 0; i < plants.size(); i++) {
            if (water < plants[i]) {
                res += 2 * i;
                water = capacity;
            }
            water -= plants[i];
        }
        return res;
    }
};
