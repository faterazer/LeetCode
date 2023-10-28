#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        make_heap(gifts.begin(), gifts.end());
        while (k-- && gifts[0] > 1) {
            pop_heap(gifts.begin(), gifts.end());
            gifts.back() = sqrt(gifts.back());
            push_heap(gifts.begin(), gifts.end());
        }
        return accumulate(gifts.begin(), gifts.end(), 0LL);
    }
};
