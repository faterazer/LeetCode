#include <string>
using namespace std;

class Solution
{
public:
    bool rotateString_MK1(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        for (size_t i = 0; i < A.size(); i++)
            if (A[i] == B[0] && rotateEqual(A, i, B))
                return true;
        return A.size() ? false : true;
    }

    bool rotateString_MK2(string A, string B)
    {
        return A.size() == B.size() && (A + A).find(B) != string::npos;
    }

private:
    bool rotateEqual(const string &A, size_t start, const string &B)
    {
        for (size_t i = 0; i < B.size(); i++)
            if (A[(start + i) % A.size()] != B[i])
                return false;
        return true;
    }
};
