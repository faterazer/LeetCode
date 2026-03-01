#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int minPartitions(string n)
    {
        return ranges::max(n) - '0';
    }
};
