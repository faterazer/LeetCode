#include <string>
using namespace std;

class Solution {
public:
    int minimumPushes(string word)
    {
        int n = word.size();
        int a = n / 8, b = n % 8;
        return (1 + a) * (4 * a + b);
    }
};
