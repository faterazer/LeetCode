#include <string>
using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        int cnt = 1;
        for (size_t i = 0; i < preorder.size(); i++) {
            if (cnt == 0)
                return false;
            if (preorder[i] == ',')
                continue;
            else if (preorder[i] == '#')
                cnt--;
            else {
                while (i < preorder.size() && preorder[i] != ',')
                    i++;
                cnt++;
            }
        }
        return cnt == 0;
    }
};
