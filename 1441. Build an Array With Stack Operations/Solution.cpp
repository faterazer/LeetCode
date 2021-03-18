#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        size_t i = 0;
        vector<string> res;
        for (int x = 1; i != target.size(); x++) {
            res.emplace_back("Push");
            if (x != target[i])
                res.emplace_back("Pop");
            else
                i++;
        }
        return res;
    }
};
