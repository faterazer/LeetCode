#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    int findRadius_MK1(vector<int> &houses, vector<int> &heaters);
    int findRadius_MK2(vector<int> &houses, vector<int> &heaters);
};

int Solution::findRadius_MK1(vector<int> &houses, vector<int> &heaters)
{
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int i = 0, radius = 0;
    for (const int &house : houses) {
        while (i < heaters.size() - 1 && heaters[i] + heaters[i + 1] <= house * 2)
            i++;
        radius = max(radius, abs(house - heaters[i]));
    }
    return radius;
}

int Solution::findRadius_MK2(vector<int> &houses, vector<int> &heaters)
{
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    for (const int &house : houses) {
        auto it = lower_bound(heaters.begin(), heaters.end(), house);
        if (it == heaters.end())
            radius = max(radius, house - heaters.back());
        else if (it == heaters.begin())
            radius = max(radius, heaters[0] - house);
        else
            radius = max(radius, min(house - *(it - 1), *it - house));
    }
    return radius;
}
