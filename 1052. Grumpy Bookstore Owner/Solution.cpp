#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int base = 0, n = customers.size();
        for (int i = 0; i < n; i++)
            base += customers[i] * (1 - grumpy[i]);

        int window_sum = 0, res = 0;
        for (int i = 0; i < minutes - 1; i++)
            window_sum += customers[i] * grumpy[i];
        for (int i = minutes - 1; i < n; i++) {
            window_sum += customers[i] * grumpy[i];
            res = max(res, base + window_sum);
            window_sum -= customers[i - minutes + 1] * grumpy[i - minutes + 1];
        }
        return res;
    }
};
