#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num)
    {
        unordered_map<char, char> mapper { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };
        for (int i = 0, j = num.size() - 1; i <= j; i++, j--)
            if (!mapper.count(num[i]) || mapper[num[i]] != num[j])
                return false;
        return true;
    }
};
