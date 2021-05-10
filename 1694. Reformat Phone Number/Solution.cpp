#include <string>
using namespace std;

class Solution
{
public:
    string reformatNumber(string number)
    {
        string res;
        int cnt = 0;
        for (size_t i = 0; i < number.size(); i++) {
            if (!isdigit(number[i]))
                continue;
            cnt++;
            if ((res.size() + 1) % 4 == 0)
                res.push_back('-');
            res.push_back(number[i]);
        }
        if (cnt > 1 && cnt % 3 == 1)
            swap(res[res.size() - 3], res[res.size() - 2]);
        return res;
    }
};
