#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fizzBuzz(int n);
};

vector<string> Solution::fizzBuzz(int n)
{
    vector<string> ret;
    for (int i = 1; i <= n; i++) {
        string s = "";
        if (i % 3 == 0)
            s += "Fizz";
        if (i % 5 == 0)
            s += "Buzz";
        if (s.empty())
            s = to_string(i);
        ret.emplace_back(s);
    }
    return ret;
}
