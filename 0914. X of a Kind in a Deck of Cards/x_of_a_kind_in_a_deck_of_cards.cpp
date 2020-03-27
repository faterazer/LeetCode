#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck);
};

bool Solution::hasGroupsSizeX(vector<int> &deck)
{
    vector<int> hash(10000, 0);
    for (const int &n : deck)
        hash[n]++;
    int g = 0;
    for (const int &h : hash) {
        if (h) {
            g = gcd(g, h);
            if (g < 2)
                return false;
        }
    }
    return true;
}
