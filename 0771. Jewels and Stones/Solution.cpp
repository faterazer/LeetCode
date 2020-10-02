#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_set<char> hash(J.begin(), J.end());
        int cnt = 0;
        for (const char &ch : S)
            if (hash.count(ch))
                cnt += 1;
        return cnt;
    }
};
