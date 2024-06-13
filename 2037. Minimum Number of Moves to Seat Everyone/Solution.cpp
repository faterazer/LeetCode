#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students)
    {
        ranges::sort(seats);
        ranges::sort(students);

        int res = 0;
        for (size_t i = 0; i < seats.size(); i++)
            res += abs(seats[i] - students[i]);
        return res;
    }
};
