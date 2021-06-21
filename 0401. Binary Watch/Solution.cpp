#include <bitset>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> readBinaryWatch(int num);
    vector<string> readBinaryWatch_UseBitset(int num);

private:
    int count(unsigned n);
};

vector<string> Solution::readBinaryWatch(int num)
{
    vector<string> ret;
    for (int hour = 0; hour < 12; hour++)
        for (int minute = 0; minute < 60; minute++)
            if (count(hour) + count(minute) == num)
                ret.emplace_back(to_string(hour) + (minute < 10 ? ":0" : ":") + to_string(minute));
    return ret;
}

int Solution::count(unsigned n)
{
    int ret = 0;
    while (n) {
        n &= n - 1;
        ret++;
    }
    return ret;
}

vector<string> Solution::readBinaryWatch_UseBitset(int num)
{
    vector<string> ret;
    for (int hour = 0; hour < 12; hour++)
        for (int minute = 0; minute < 60; minute++)
            if (bitset<10>(hour << 6 | minute).count() == num)
                ret.emplace_back(to_string(hour) + (minute < 10 ? ":0" : ":") + to_string(minute));
    return ret;
}
