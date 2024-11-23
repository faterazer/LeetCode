#include <cmath>
#include <vector>
using namespace std;

constexpr int MAX_LEN = 31622;
vector<int> pre_sum(MAX_LEN + 1, 1);

auto init = [] {
    vector<int> primes;
    pre_sum[0] = pre_sum[1] = 0;
    for (int i = 2; i <= MAX_LEN; ++i) {
        if (pre_sum[i])
            primes.emplace_back(i);
        for (size_t j = 0; j < primes.size() && primes[j] * i <= MAX_LEN; ++j) {
            pre_sum[primes[j] * i] = 0;
            if (i % primes[j] == 0)
                break;
        }
        pre_sum[i] += pre_sum[i - 1];
    }
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r)
    {
        int beg = sqrt(l - 1), end = sqrt(r);
        return r - l + 1 - pre_sum[end] + pre_sum[beg];
    }
};
