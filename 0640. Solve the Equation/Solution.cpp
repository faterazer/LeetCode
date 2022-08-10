#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string solveEquation(string equation)
    {
        int idx = equation.find('=');
        string left_eq = equation.substr(0, idx);
        string right_eq = equation.substr(idx + 1);
        pair<int, int> left = parse(left_eq);
        pair<int, int> right = parse(right_eq);
        int l = left.first - right.first;
        int r = right.second - left.second;
        if (l == 0 && r != 0)
            return "No solution";
        else if (l == 0)
            return "Infinite solutions";
        else
            return "x=" + to_string(r / l);
    }

private:
    pair<int, int> parse(string& s)
    {
        s.push_back('+');
        size_t i = 0, j = 0;
        int sign = 1;
        if (s[0] == '-' || s[0] == '+') {
            sign = s[0] == '+' ? 1 : -1;
            ++i;
            ++j;
        }
        int factor = 0, val = 0;
        for (i = s.find_first_of("+-", i); i != string::npos; j = i + 1, i = s.find_first_of("+-", i + 1)) {
            if (s[i - 1] == 'x')
                factor += sign * (i - j - 1 != 0 ? stoi(s.substr(j, i - j - 1)) : 1);
            else
                val += sign * stoi(s.substr(j, i - j));
            sign = s[i] == '+' ? 1 : -1;
        }
        return make_pair(factor, val);
    }
};
