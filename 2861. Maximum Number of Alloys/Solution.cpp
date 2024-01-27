#include <functional>
#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
    {
        function<bool(long long)> valid = [&](long long m) -> bool {
            for (const vector<int>& c : composition) {
                long long sum = 0;
                for (int i = 0; i < n; i++)
                    sum += max(c[i] * m - stock[i], 0LL) * cost[i];
                if (sum <= budget)
                    return true;
            }
            return false;
        };

        int left = 1, right = ranges::min(stock) + budget + 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (valid(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};
