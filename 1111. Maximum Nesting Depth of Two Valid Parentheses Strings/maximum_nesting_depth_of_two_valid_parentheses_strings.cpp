#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit_MK1(string seq);
    vector<int> maxDepthAfterSplit_MK2(string seq);
};

vector<int> Solution::maxDepthAfterSplit_MK1(string seq)
{
    vector<int> ret;
    int d = 0;
    for (const char &c : seq) {
        if (c == '(') {
            ret.emplace_back(d % 2);
            d++;
        }
        else {
            d--;
            ret.emplace_back(d % 2);
        }
    }
    return ret;
}

vector<int> Solution::maxDepthAfterSplit_MK2(string seq)
{
    vector<int> ret;
    for (size_t i = 0; i < seq.size(); i++)
        ret.emplace_back(i & 1 ^ (seq[i] == '('));
    return ret;
}
