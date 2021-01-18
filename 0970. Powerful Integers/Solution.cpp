#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        unordered_set<int> res;
        for (int i = 1; i <= bound; i *= x) {
            for (int j = 1; i + j <= bound; j *= y) {
                res.emplace(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(res.begin(), res.end());
    }
};
