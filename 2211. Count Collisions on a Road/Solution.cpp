#include <algorithm>
#include <ranges>
#include <string>
using namespace std;

class Solution {
public:
    int countCollisions(string directions)
    {
        auto beg = ranges::find_if(directions, [](char c) { return c != 'L'; });
        auto end = ranges::find_if(directions | views::reverse, [](char c) { return c != 'R'; }).base();
        if (beg >= end)
            return 0;
        return ranges::count_if(beg, end, [](char c) { return c != 'S'; });
    }
};
