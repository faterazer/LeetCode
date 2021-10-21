#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
    int countSegments(string s);
};

int Solution::countSegments(string s)
{
    stringstream in(s);
    string word;
    int count = 0;
    while (in >> word)
        count++;
    return count;
}
