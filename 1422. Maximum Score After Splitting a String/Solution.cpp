#include <string>
using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int leftSum = s[0] == '0';
        int rightSum = 0;
        for (size_t i = 1; i < s.size(); i++)
            rightSum += s[i] == '1';
        int res = leftSum + rightSum;
        for (size_t i = 1; i < s.size() - 1; i++) {
            leftSum += s[i] == '0';
            rightSum -= s[i] == '1';
            res = max(res, leftSum + rightSum);
        }
        return res;
    }
};
