#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    int countVowelStrings_MK1(int n)
    {
        vector<int> buff(5, 1);
        for (int i = 2; i <= n; ++i) {
            int sum = 0;
            for (int j = 0; j < buff.size(); ++j) {
                sum += buff[j];
                buff[j] = sum;
            }
        }
        return accumulate(buff.begin(), buff.end(), 0);
    }

private:
    int countVowelStrings_MK2(int n)
    {
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
    }
};
