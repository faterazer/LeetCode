#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (const char& ch : s) {
            if (ch == 'c') {
                if (stk.size() < 2)
                    return false;
                char b = stk.top();
                stk.pop();
                char a = stk.top();
                stk.pop();
                if (a != 'a' || b != 'b')
                    return false;
            } else
                stk.emplace(ch);
        }
        return stk.empty();
    }
};
