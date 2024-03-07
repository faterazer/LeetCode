#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n);
private:
    void generate(vector<string> &vs, string s, int lpairs, int rpairs);
};

vector<string> Solution::generateParenthesis(int n)
{
    vector<string> ret;
    generate(ret, "", n, n);
    return ret;
}

void Solution::generate(vector<string> &vs, string s, int lpairs, int rpairs)
{
    if (rpairs < lpairs)
        return;
    if (lpairs == 0 && rpairs == 0) {
        vs.emplace_back(s);
        return;
    }
    if (lpairs)
        generate(vs, s + "(", lpairs - 1, rpairs);
    if (rpairs)
        generate(vs, s + ")", lpairs, rpairs - 1);
}
