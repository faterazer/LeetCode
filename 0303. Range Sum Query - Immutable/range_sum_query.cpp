#include <numeric>
#include <vector>
using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums) : sum_vec(nums.size() + 1, 0)
    {
        for (size_t i = 0; i < nums.size(); i++)
            sum_vec[i + 1] = sum_vec[i] + nums[i];
    }

    int sumRange(int i, int j)
    {
        return sum_vec[j + 1] - sum_vec[i];
    }
private:
    vector<int> sum_vec;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
