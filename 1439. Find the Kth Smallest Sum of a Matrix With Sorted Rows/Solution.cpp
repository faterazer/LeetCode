#include <queue>
#include <tuple>
#include <vector>
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        vector<int> buff{0};
        for (const vector<int> &row : mat)
            buff = kSmallestPairs(buff, row, k);
        return buff.back();
    }

private:
    vector<int> kSmallestPairs(const vector<int> &A, const vector<int> &B, size_t k)
    {
        vector<int> res;
        priority_queue<tuple<int, int, int>> pq;
        int m = A.size(), n = B.size();
        pq.emplace(-A[0] - B[0], 0, 0);
        while (!pq.empty() && res.size() < k)
        {
            auto [neg_sum, i, j] = pq.top();
            pq.pop();
            res.emplace_back(-neg_sum);
            if (j == 0 && i + 1 < m)
                pq.emplace(-A[i + 1] - B[j], i + 1, j);
            if (j + 1 < n)
                pq.emplace(-A[i] - B[j + 1], i, j + 1);
        }
        return res;
    }
};
