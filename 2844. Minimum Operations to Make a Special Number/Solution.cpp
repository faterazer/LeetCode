#include <string>
using namespace std;

class Solution {
public:
    int minimumOperations(string num)
    {
        int n = num.size();
        bool found0 = false, found5 = false;
        for (int i = n - 1; i >= 0; i--) {
            char c = num[i];
            if ((found0 && (c == '0' || c == '5')) || (found5 && (c == '2' || c == '7')))
                return num.size() - i - 2;
            if (c == '0')
                found0 = true;
            else if (c == '5')
                found5 = true;
        }
        return n - found0;
    }
};
