#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        size_t idx = s.find('6');
        if (idx != string::npos)
            s[idx] = '9';
        return stoi(s);
    }
};
