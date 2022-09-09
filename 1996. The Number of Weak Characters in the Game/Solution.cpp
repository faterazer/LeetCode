#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        sort(properties.begin(), properties.end(), [](const vector<int>& left, const vector<int>& right) {
            return left[0] != right[0] ? left[0] > right[0] : left[1] < right[1];
        });
        int max_def = 0, res = 0;
        for (const vector<int>& property : properties) {
            if (property[1] < max_def)
                ++res;
            else
                max_def = property[1];
        }
        return res;
    }
};
