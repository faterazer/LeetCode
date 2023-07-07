#include <vector>
using namespace std;

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder)
    {
        int lower_bound = INT_MIN, tp = 0;
        for (int p : preorder) {
            if (p < lower_bound)
                return false;
            while (tp > 0 && p > preorder[tp - 1])
                lower_bound = preorder[--tp];
            preorder[tp++] = p;
        }
        return true;
    }
};
