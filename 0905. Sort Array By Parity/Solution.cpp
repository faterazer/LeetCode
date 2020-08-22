#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int front = 0, rear = A.size() - 1;
        while (front < rear) {
            if (A[front] % 2)
                swap(A[front], A[rear--]);
            else
                front++;
        }
        return A;
    }
};
