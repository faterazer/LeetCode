#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int len = flowerbed.size();
        for (int i = 0; i < len; i++) {
            if (!flowerbed[i] && (i - 1 < 0 || !flowerbed[i - 1]) && (i + 1 >= len || !flowerbed[i + 1])) {
                n -= 1;
                flowerbed[i] = 1;
            }
            if (n == 0)
                return true;
        }
        return false;
    }
};
