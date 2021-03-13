#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        int res = 0, max = 0, tmp;
        unordered_map<int, int> counter;
        for (int i = 1; i <= n; i++) {
            tmp = sumOfDigits(i);
            counter[tmp]++;
            if (counter[tmp] == max)
                res++;
            else if (counter[tmp] > max) {
                max = counter[tmp];
                res = 1;
            }
        }
        return res;
    }

private:
    int sumOfDigits(int n)
    {
        int sum = 0;
        for (; n; n /= 10)
            sum += n % 10;
        return sum;
    }
};
