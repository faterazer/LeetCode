#include <ranges>
#include <vector>
using namespace std;

class Solution {
public:
    // 枚举中间点。时间复杂度：O(n^2)，空间复杂度：O(1)
    int numTeams_MK1(vector<int>& rating)
    {
        int n = rating.size(), res = 0;
        for (int j = 0; j < n; j++) {
            int iless = 0, imore = 0;
            int kless = 0, kmore = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j])
                    iless++;
                else if (rating[i] > rating[j])
                    imore++;
            }
            for (int k = n - 1; k > j; k--) {
                if (rating[k] < rating[j])
                    kless++;
                else if (rating[k] > rating[j])
                    kmore++;
            }
            res += iless * kmore + kless * imore;
        }
        return res;
    }

    // 使用树状数组（Binary Indexed Tree）。时间复杂度：O(nlgn)，空间复杂度：O(n)
    int numTeams_MK2(vector<int>& rating) {
        int max_rating = *ranges::max_element(rating);
        vector<int> left_BIT(max_rating + 1, 0), right_BIT(max_rating + 1, 0);

        for (int r : rating)
            updateBIT(right_BIT, r, 1);
        
        int res = 0;
        for (int r : rating) {
            updateBIT(right_BIT, r, -1);
            int left_less = getPrefixSum(left_BIT, r - 1);
            int left_more = getPrefixSum(left_BIT, max_rating) - getPrefixSum(left_BIT, r);
            int right_less = getPrefixSum(right_BIT, r - 1);
            int right_more = getPrefixSum(right_BIT, max_rating) - getPrefixSum(right_BIT, r);
            updateBIT(left_BIT, r, 1);

            res += left_less * right_more + left_more * right_less;
        }
        return res;
    }

private:
    void updateBIT(vector<int> &BIT, int index, int val) {
        while (index < BIT.size()) {
            BIT[index] += val;
            index += index & (-index);
        }
    }

    int getPrefixSum(vector<int> &BIT, int index) {
        int res = 0;
        while (index > 0) {
            res += BIT[index];
            index -= index & (-index);
        }
        return res;
    }
};
