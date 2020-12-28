#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSpecialEquivGroups(vector<string> &A)
    {
        unordered_set<string> uset;
        for (string &s : A) {
            string even, odd;
            for (size_t i = 0; i < s.size(); i++) {
                if (i % 2 == 0)
                    even.push_back(s[i]);
                else
                    odd.push_back(s[i]);
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            uset.insert(even + odd);
        }
        return uset.size();
    }
};
