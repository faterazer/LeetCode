#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess);
};

string Solution::getHint(string secret, string guess)
{
    vector<int> buff(10, 0);
    int A = 0, B = 0;
    for (size_t i = 0; i < secret.size(); i++) {
        if (secret[i] == guess[i])
            A++;
        else {
            if (buff[guess[i] - '0']-- > 0)
                B++;
            if (buff[secret[i] - '0']++ < 0)
                B++;
        }
    }
    return to_string(A) + 'A' + to_string(B) + 'B';
}
