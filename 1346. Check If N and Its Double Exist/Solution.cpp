#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> appeared;
        for (const int &x : arr) {
            if (appeared.count(x * 2) || (!x % 2 && appeared.count(x / 2)))
                return true;
            appeared.emplace(x);
        }
        return false;
    }
};
