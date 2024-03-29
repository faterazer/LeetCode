#include <string>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k)
    {
        string res(n, 'a');
        k -= n;
        while (k > 0) {
            res[--n] += min(25, k);
            k -= 25;
        }
        return res;
    }
};
