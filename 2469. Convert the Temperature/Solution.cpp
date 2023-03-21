#include <vector>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius)
    {
        return vector<double> { celsius + 273.15, celsius * 1.8 + 32.0 };
    }
};
