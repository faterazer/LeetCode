#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        vector<int> buff(N + 1, 0);
        for (const vector<int> &p : trust) {
            buff[p[0]]--;
            buff[p[1]]++;
        }
        for (size_t i = 1; i < buff.size(); i++)
            if (buff[i] == N - 1)
                return i;
        return -1;
    }
};
