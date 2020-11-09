#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int index = (upper_bound(letters.begin(), letters.end(), target) - letters.begin()) % letters.size();
        return letters[index];
    }
};
