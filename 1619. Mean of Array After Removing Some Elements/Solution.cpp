#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
    double trimMean_MK1(vector<int> &arr)
    {
        int seg = arr.size() / 20;
        nth_element(arr.begin(), arr.begin() + seg, arr.end());
        nth_element(arr.begin() + seg, arr.begin() + arr.size() - seg, arr.end());
        return accumulate(arr.begin() + seg, arr.begin() + arr.size() - seg, 0.0) / (arr.size() * 0.9);
    }

    double trimMean_MK2(vector<int> &arr)
    {
        int seg = arr.size() / 20, size = arr.size();
        kth_element(arr, 0, seg, arr.size());
        kth_element(arr, seg, size - seg, size);
        return accumulate(arr.begin() + seg, arr.begin() + arr.size() - seg, 0.0) / (size * 0.9);
    }

private:
    void kth_element(vector<int> &arr, int l, int k, int r)
    {
        if (l >= r || k < l || k >= r)
            return;
        int m = l + ((r - l) >> 1), last = l;
        // 三数取中
        if (arr[m] < arr[l])
            swap(arr[m], arr[l]);
        if (arr[r - 1] < arr[m])
            swap(arr[r - 1], arr[m]);
        if (arr[m] < arr[l])
            swap(arr[m], arr[l]);
        swap(arr[l], arr[m]);
        for (int i = l + 1; i < r; i++) {
            if (arr[i] <= arr[l])
                swap(arr[i], arr[++last]);
        }
        swap(arr[l], arr[last]);
        if (k < last)
            kth_element(arr, l, k, last);
        else if (k > last)
            kth_element(arr, last + 1, k, r);
    }
};
