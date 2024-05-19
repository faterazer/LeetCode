#include <vector>
using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k)
    {
        int res = arr[0], cnt = 0;
        for (size_t i = 1; i < arr.size() && cnt < k; i++) {
            if (res > arr[i])
                cnt++;
            else {
                res = arr[i];
                cnt = 1;
            }
        }
        return res;
    }
};
