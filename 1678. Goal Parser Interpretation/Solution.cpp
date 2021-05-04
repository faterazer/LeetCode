#include <string>
using namespace std;

class Solution
{
public:
    string interpret(string command)
    {
        string res;
        for (size_t i = 0; i < command.size(); i++) {
            if (command[i] == 'G')
                res.push_back(command[i]);
            else if (command[i] == ')') {
                if (command[i - 1] == '(')
                    res.push_back('o');
                else
                    res += "al";
            }
        }
        return res;
    }
};
