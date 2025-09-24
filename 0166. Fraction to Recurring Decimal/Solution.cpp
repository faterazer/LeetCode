#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
            return "0";

        long long a = numerator, b = denominator;
        string ans = ((a < 0) ^ (b < 0)) ? "-" : "";
        a = abs(a);
        b = abs(b);

        long long q = a / b, r = a % b;
        if (r == 0)
            return ans + to_string(q);
        else
            ans += to_string(q) + ".";

        unordered_map<int, int> r2pos { { r, ans.size() } };
        while (r) {
            r *= 10;
            q = r / b;
            r %= b;
            ans.push_back('0' + q);
            if (r2pos.contains(r)) {
                ans.insert(r2pos[r], "(");
                ans.push_back(')');
                return ans;
            } else
                r2pos[r] = ans.size();
        }
        return ans;
    }
};
