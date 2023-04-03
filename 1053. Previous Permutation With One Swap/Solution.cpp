#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr)
    {
        int i = arr.size() - 1;
        while (i > 0 && arr[i] >= arr[i - 1])
            i--;
        if (i == 0)
            return arr;
        i -= 1;
        int j = arr.size() - 1;
        while (arr[j] >= arr[i] || arr[j] == arr[j - 1])
            j--;
        swap(arr[i], arr[j]);
        return arr;
    }
};
