#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int lines = 1, width = 0;
        for (const char &ch : S) {
            if (width + widths[ch - 'a'] > 100) {
                width = 0;
                lines++;
            }
            width += widths[ch - 'a'];
        }
        return {lines, width};
    }
};
