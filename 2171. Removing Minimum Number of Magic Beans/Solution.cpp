#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans)
    {
        sort(beans.begin(), beans.end());
        unsigned long sum = 0, max_val = 0;
        for (size_t i = 0; i < beans.size(); i++) {
            sum += beans[i];
            max_val = max(max_val, beans[i] * (beans.size() - i));
        }
        return sum - max_val;
    }
};
