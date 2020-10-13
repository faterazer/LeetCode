#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool buddyStrings(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        vector<int> diff;
        for (size_t i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                if (diff.size() == 2)
                    return false;
                diff.emplace_back(i);
            }
        }
        if (diff.size() == 0)
            return unordered_set<char>(A.begin(), A.end()).size() < A.size();
        else if (diff.size() == 1)
            return false;
        else  // diff.size() == 2
            return A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};
