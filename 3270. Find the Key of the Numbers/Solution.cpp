#include <algorithm>
using namespace std;

class Solution {
public:
    int generateKey(int num1, int num2, int num3)
    {
        int ans = 0;
        for (int pow10 = 1; num1 && num2 && num3; pow10 *= 10) {
            ans += min({ num1 % 10, num2 % 10, num3 % 10 }) * pow10;
            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
        }
        return ans;
    }
};
