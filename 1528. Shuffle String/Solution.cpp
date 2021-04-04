#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int size = s.size();
        for (int i = 0; i < size; ) {
            if (i == indices[i])
                i++;
            else {
                swap(s[i], s[indices[i]]);
                swap(indices[i], indices[indices[i]]);
            }
        }
        return s;
    }
};
