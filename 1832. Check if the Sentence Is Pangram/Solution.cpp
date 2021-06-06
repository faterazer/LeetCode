#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        return unordered_set<char>(sentence.begin(), sentence.end()).size() == 26;
    }
};
