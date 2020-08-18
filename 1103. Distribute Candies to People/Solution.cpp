#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> distributeCandies_MK1(int candies, int num_people); // BF
    vector<int> distributeCandies_MK2(int candies, int num_people); // Math
};

vector<int> Solution::distributeCandies_MK1(int candies, int num_people)
{
    vector<int> ret(num_people, 0);
    int j = 1;
    for (; candies > j; candies -= j, j++)
            ret[(j - 1) % num_people] += j;
    ret[(j - 1) % num_people] += candies;
    return ret;
}

vector<int> Solution::distributeCandies_MK2(int candies, int num_people)
{
    int n = static_cast<int>(sqrt(2 * candies + 0.25) - 0.5);
    int rows = n / num_people, cols = n % num_people;
    vector<int> ret(num_people, 0);
    for (int i = 0; i < num_people; i++) {
        ret[i] += (i + 1) * rows + rows * (rows - 1) * num_people * 0.5;
        if (i < cols)
            ret[i] += 1 + i + rows * num_people;
    }
    ret[cols] += candies - n * (1 + n) * 0.5;
    return ret;
}
