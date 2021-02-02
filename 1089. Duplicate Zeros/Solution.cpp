#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size(), zeros = count(arr.begin(), arr.end(), 0);
        for (int i = n - 1; i >= 0 && zeros; i--) {
            if (i + zeros < n)
                arr[i + zeros] = arr[i];
            if (!arr[i] && i + (--zeros) < n)
                arr[i + zeros] = arr[i];
        }
    }
};
