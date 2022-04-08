#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> stk;
        int i = 0;
        for (const int& e : pushed) {
            stk.emplace(e);
            while (!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i += 1;
            }
        }
        return stk.empty();
    }
};
