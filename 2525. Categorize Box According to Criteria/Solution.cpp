#include <string>
using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool is_bulky = max(length, max(width, height)) >= 10000 || 1LL * length * width * height >= 1000000000;
        bool is_heavy = mass >= 100;
        if (is_bulky && is_heavy)
            return "Both";
        else if (!is_bulky && !is_heavy)
            return "Neither";
        else if (is_bulky)
            return "Bulky";
        else
            return "Heavy";
    }
};
