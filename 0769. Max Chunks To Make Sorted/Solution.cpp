#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int res = 0, n = arr.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(arr[i], mx);
            if (mx == i)
                ++res;
        }
        return res;
    }
};
