#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums);
};

int Solution::thirdMax(vector<int> &nums)
{
    set<int> top3;
    for (const int &n : nums) {
        top3.insert(n);
        if (top3.size() > 3)
            top3.erase(top3.begin());
    }
    return top3.size() < 3 ? *top3.rbegin() : *top3.begin();
}
