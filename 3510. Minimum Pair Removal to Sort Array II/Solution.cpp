#include <numeric>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums)
    {
        int n = nums.size(), dec = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1])
                ++dec;
            pq.emplace(nums[i] + nums[i + 1], i);
        }

        vector<int> prev(n), next(n);
        iota(prev.begin(), prev.end(), -1);
        iota(next.begin(), next.end(), 1);

        int result = 0;
        vector<long long> A(nums.begin(), nums.end());
        while (dec) {
            auto [s, i] = pq.top();
            pq.pop();
            if (next[i] >= n || 0LL + A[i] + A[next[i]] != s)
                continue;
            ++result;
            int prev_i = prev[i];
            if (prev_i > -1) {
                dec -= A[prev_i] > A[i];
                dec += A[prev_i] > s;
                pq.emplace(A[prev_i] + s, prev_i);
            }
            int next_i = next[i];
            dec -= A[i] > A[next_i];
            int next_next_i = next[next_i];
            if (next_next_i < n) {
                dec -= A[next_i] > A[next_next_i];
                dec += s > A[next_next_i];
                prev[next_next_i] = i;
                pq.emplace(s + A[next_next_i], i);
            }
            A[i] = s;
            next[i] = next_next_i;
            next[next_i] = n;
        }
        return result;
    }
};
