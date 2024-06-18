#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount)
    {
        istringstream in(sentence);
        string res, s;
        while (in >> s) {
            if (!res.empty())
                res += ' ';
            if (isPrice(s)) {
                double price = stoll(s.substr(1)) * (1.0 - discount / 100.0);
                ostringstream out;
                out << fixed << setprecision(2) << '$' << price;
                res += out.str();
            } else
                res += s;
        }
        return res;
    }

private:
    bool isPrice(const string& s)
    {
        return s[0] == '$' && s.size() > 1 && all_of(s.begin() + 1, s.end(), ::isdigit);
    }
};
