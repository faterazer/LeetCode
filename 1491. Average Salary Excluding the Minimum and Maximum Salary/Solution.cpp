#include <vector>
using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int sum = 0, mx = salary[0], mn = salary[0];
        for (const int &x : salary) {
            sum += x;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        return static_cast<double>(sum - mx - mn) / (salary.size() - 2);
    }
};
