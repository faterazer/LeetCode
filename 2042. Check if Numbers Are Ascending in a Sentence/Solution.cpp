#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s)
    {
        istringstream in(s);
        string token;
        int prev = 0;
        while (in >> token) {
            if (isdigit(token[0])) {
                int n = stoi(token);
                if (n <= prev)
                    return false;
                prev = n;
            }
        }
        return true;
    }
};
