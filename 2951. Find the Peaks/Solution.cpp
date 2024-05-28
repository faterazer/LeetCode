#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain)
    {
        vector<int> res;
        for (size_t i = 1; i < mountain.size() - 1; i++)
            if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
                res.emplace_back(i);
        return res;
    }
};
