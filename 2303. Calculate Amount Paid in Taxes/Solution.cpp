#include <vector>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income)
    {
        double tax = 0.0, prev = 0.0;
        for (const vector<int> &bracket : brackets) {
            int upper = bracket[0], percent = bracket[1];
            tax += (min(income, upper) - prev) * percent / 100;
            prev = upper;
            if (income <= upper)
                break;
        }
        return tax;
    }
};
