#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int lcnt = 0, rcnt = 0, state = 0;
        for (size_t i = 0; i < boxes.size(); i++) {
            if (boxes[i] == '1') {
                state += i;
                ++rcnt;
            }
        }

        vector<int> res(boxes.size(), 0);
        for (size_t i = 0; i < res.size(); i++) {
            res[i] = state;
            if (boxes[i] == '1') {
                ++lcnt;
                --rcnt;
            }
            state = state + lcnt - rcnt;
        }
        return res;
    }
};
