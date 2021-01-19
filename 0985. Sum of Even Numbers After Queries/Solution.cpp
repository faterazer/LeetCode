#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        int sum = 0;
        for (const int &x : A)
            if (!(x & 1))
                sum += x;
        
        vector<int> ret;
        for (const vector<int> &query : queries) {
            int &val = A[query[1]];
            if (!(val & 1))
                sum -= val;
            val += query[0];
            if (!(val & 1))
                sum += val;
            ret.emplace_back(sum);
        }
        return ret;
    }
};
