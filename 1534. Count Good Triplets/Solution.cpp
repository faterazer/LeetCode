#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int countGoodTriplets_MK1(vector<int> &arr, int a, int b, int c)
    {
        int res = 0;
        for (size_t i = 0; i < arr.size() - 2; i++) {
            for (size_t j = i + 1; j < arr.size() - 1; j++) {
                if (abs(arr[i] - arr[j]) <= a) {
                    for (size_t k = j + 1; k < arr.size(); k++)
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            res++;
                }
            }
        }
        return res;
    }

    int countGoodTriplets_MK2(vector<int> &arr, int a, int b, int c)
    {
        int res = 0, l, r;
        vector<int> preSum(1001, 0);
        for (size_t j = 0; j < arr.size(); j++) {
            for (size_t k = j + 1; k < arr.size(); k++) {
                if (abs(arr[j] - arr[k]) <= b) {
                    l = max(0, max(arr[j] - a, arr[k] - c));
                    r = min(1000, min(arr[j] + a, arr[k] + c));
                    if (l <= r)
                        res += preSum[r] - (l ? preSum[l - 1] : 0);
                }
            }
            for (int k = arr[j]; k <= 1000; k++)
                preSum[k]++;
        }
        return res;
    }
};
