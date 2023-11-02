#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int countPoints(string rings)
    {
        int cnt[10] = { 0 };
        string colors = "RGB";
        for (size_t i = 0; i < rings.size(); i += 2) {
            int c = colors.find(rings[i]), rod = rings[i + 1] - '0';
            cnt[rod] |= 1 << c;
        }
        return count(begin(cnt), end(cnt), 7);
    }
};
