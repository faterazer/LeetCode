#include <vector>
using namespace std;

class Solution
{
public:
    void reverseWords(vector<char> &s)
    {
        s.emplace_back(' ');
        for (size_t i = 0, j = 0; j < s.size(); j++)
        {
            if (s[j] == ' ')
            {
                reverse(s, i, j - 1);
                i = j + 1;
            }
        }
        s.pop_back();
        reverse(s, 0, s.size() - 1);
    }

private:
    void reverse(vector<char> &s, int lo, int hi)
    {
        for (; lo < hi; lo++, hi--)
            swap(s[lo], s[hi]);
    }
};
