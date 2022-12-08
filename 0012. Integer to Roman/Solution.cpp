#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num)
    {
        string res;
        for (const auto &[value, s] : mapping) {
            while (num >= value) {
                num -= value;
                res += s;
            }
        }
        return res;
    }

private:
    const vector<pair<int, string>> mapping {
        { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" },
        { 100, "C" }, { 90, "XC" }, { 50, "L" }, { 40, "XL" },
        { 10, "X" }, { 9, "IX" }, { 5, "V" }, { 4, "IV" }, { 1, "I" }
    };
};
