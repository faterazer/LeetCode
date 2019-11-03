#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string);
};

int Solution::lengthOfLastWord(string s)
{
    int ans = 0;
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ')
        i--;
    while (i >= 0 && s[i] != ' ') {
        ans++;
        i--;
    }
    return ans;
}

int main()
{
    string testCase = "Hello World";
    // string testCase = "a ";
    cout << Solution().lengthOfLastWord(testCase) << endl;
    return 0;
}