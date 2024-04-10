#include <string>
using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary)
    {
        int i = binary.find('0');
        if (i == string::npos)
            return binary;

        int cnt = count(binary.begin() + i, binary.end(), '1');
        return string(binary.size() - 1 - cnt, '1') + '0' + string(cnt, '1');
    }
};
