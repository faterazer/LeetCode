#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    Solution();
    bool isValid(string);
private:
    map<char, char> mapping;
};

Solution::Solution()
{
    mapping[')'] = '(';
    mapping[']'] = '[';
    mapping['}'] = '{';
}

bool Solution::isValid(string s)
{
    stack<char> stk;
    stk.push('#');  // 避免栈空时，调用 top(). avoid to invoke top() while stack is empty
    for (size_t i = 0; i != s.size(); i++) {
        // s[i] is '(' or '[' or '{'
        if (mapping.find(s[i]) == mapping.end())
            stk.push(s[i]);
        else {  // s[i] is ')' or ']' or '}'.
            if (stk.top() == mapping[s[i]])
                stk.pop();
            else
                return false;
        }
    }
    return stk.size() > 1 ? false : true;
}