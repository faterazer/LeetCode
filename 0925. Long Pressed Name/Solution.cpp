#include <string>
using namespace std;

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 0, j = 0;
        for (; j < typed.size(); j++) {
            if (i < name.size() && name[i] == typed[j])
                i++;
            else if (j == 0 || typed[j] != typed[j - 1])
                return false;
        }
        return i == name.size();
    }
};
