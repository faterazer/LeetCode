#include <format>
#include <string>
using namespace std;

class Solution {
public:
    string convertDateToBinary(string date)
    {
        return format("{:b}-{:b}-{:b}", stoi(date.substr(0, 4)), stoi(date.substr(5, 2)), stoi(date.substr(8, 2)));
    }
};
