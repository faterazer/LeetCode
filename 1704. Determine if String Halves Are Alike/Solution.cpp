#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        int cnt = 0, halfn = s.size() / 2, n = s.size();
        for (int i = 0; i < halfn; i++)
            cnt += vowels.count(s[i]);
        for (int i = halfn; i < n; i++)
            if (vowels.count(s[i]) && --cnt < 0)
                return false;
        return cnt == 0;
    }

private:
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
};
