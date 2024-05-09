#include <vector>
using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB)
    {
        int res = 0, n = plants.size(), water_a = capacityA, water_b = capacityB;
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (i == j)
                res += max(water_a, water_b) < plants[i];
            else {
                if (water_a < plants[i]) {
                    water_a = capacityA;
                    res++;
                }
                if (water_b < plants[j]) {
                    water_b = capacityB;
                    res++;
                }
                water_a -= plants[i];
                water_b -= plants[j];
            }
        }
        return res;
    }
};
