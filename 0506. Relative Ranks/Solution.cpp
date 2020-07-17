#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Athlete
{
public:
    int score = 0;
    int index = 0;
};

bool comp(const Athlete &left, const Athlete &right)
{
    return left.score > right.score;
}

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<Athlete> athletes(nums.size());
        for (size_t i = 0; i < nums.size(); i++) {
            athletes[i].score = nums[i];
            athletes[i].index = i;
        }
        sort(athletes.begin(), athletes.end(), comp);
        vector<string> ret(nums.size());
        for (size_t i = 0; i < athletes.size(); i++) {
            if (i == 0)
                ret[athletes[i].index] = "Gold Medal";
            else if (i == 1)
                ret[athletes[i].index] = "Silver Medal";
            else if (i == 2)
                ret[athletes[i].index] = "Bronze Medal";
            else
                ret[athletes[i].index] = to_string(i + 1);
        }
        return ret;
    }
};
