#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> index_map;
        for (size_t i = 0; i < list1.size(); i++)
            index_map[list1[i]] = i;
        vector<string> ret;
        int min_sum = 2000;
        for (size_t i = 0; i < list2.size(); i++) {
            if (!index_map.count(list2[i]))
                continue;
            int sum = index_map[list2[i]] + i;
            if (sum == min_sum)
                ret.emplace_back(list2[i]);
            else if (sum < min_sum) {
                ret.clear();
                ret.emplace_back(list2[i]);
                min_sum = sum;
            }
        }
        return ret;
    }
};
