#include <vector>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int count[] = {0, 0};
        for (const int &student : students)
            count[student]++;
        for (size_t i = 0; i < sandwiches.size() && count[sandwiches[i]]; i++)
            count[sandwiches[i]]--;
        return count[0] + count[1];
    }
};
