#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n < 2)
            return n;
        vector<int> vi(n + 1);
        vi[0] = 0;
        vi[1] = 1;
        for (int i = 2; i <= n; i++)
            vi[i] = i % 2 == 0 ? vi[i / 2] : vi[i / 2] + vi[i / 2 + 1];
        return *max_element(vi.begin(), vi.end());
    }
};
