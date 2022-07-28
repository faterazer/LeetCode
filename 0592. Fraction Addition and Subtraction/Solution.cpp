#include <numeric>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string fractionAddition_MK1(string expression)
    {
        expression.push_back('+');
        int numerator1 = 0, denominator1 = 1, sign = 1, numerator2 = 0, denominator2 = 0, num = 0;
        int i = 0, n = expression.size();
        if (expression[i] == '+' || expression[i] == '-')
            if (expression[i++] == '-')
                sign = -1;
        while (i < n) {
            if (expression[i] == '+' || expression[i] == '-') {
                denominator2 = num;
                num = 0;

                numerator1 = numerator1 * denominator2 + sign * numerator2 * denominator1;
                denominator1 *= denominator2;
                sign = expression[i] == '+' ? 1 : -1;
            } else if (expression[i] == '/') {
                numerator2 = num;
                num = 0;
            } else {
                num = num * 10 + expression[i] - '0';
            }
            ++i;
        }
        if (numerator1 == 0)
            return "0/1";

        int g = gcd(numerator1, denominator1);
        return to_string(numerator1 / g) + "/" + to_string(denominator1 / g);
    }

    string fractionAddition_MK2(string expression)
    {
        istringstream in(expression);
        int A = 0, B = 1, a, b;
        char _;
        while (in >> a >> _ >> b) {
            A = A * b + a * B;
            B *= b;
            int g = gcd(A, B);
            A /= g;
            B /= g;
        }
        return to_string(A) + '/' + to_string(B);
    }
};
