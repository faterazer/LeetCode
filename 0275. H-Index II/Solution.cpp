#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int left = 0, right = citations.size() - 1, n = citations.size();
        while (left <= right) {
            int m = left + ((right - left) >> 1);
            if (citations[m] < n - m)
                left = m + 1;
            else
                right = m - 1;
        }
        return n - left;
    }
};
