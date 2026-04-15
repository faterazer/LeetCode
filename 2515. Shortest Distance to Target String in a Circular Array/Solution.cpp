#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex)
    {
        int n = ssize(words);
        for (int i = 0; i <= n / 2; ++i)
            if (words[(startIndex - i + n) % n] == target || words[(startIndex + i) % n] == target)
                return i;
        return -1;
    }
};
