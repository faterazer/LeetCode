#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int);
};

string Solution::countAndSay(int n)
{
    string ans = "1";
    if (n < 1 || n > 30)
        return 0;
    
    for (int i = 1; i != n; i++) {
        char ch = ans.front();
        int count = 1;
        string temp_ans;
        for (size_t j = 1; j != ans.size(); j++) {
            if (ans[j] == ch)
                count++;
            else {
                temp_ans.push_back('0' + count);
                temp_ans.push_back(ch);
                ch = ans[j];
                count = 1;
            }
        }
        temp_ans.push_back('0' + count);
        temp_ans.push_back(ch);
        ans = temp_ans;
    }
    return ans;
}

int main()
{
    for (int i = 1; i <= 30; i++)
        cout << Solution().countAndSay(i) << endl;
    return 0;
}