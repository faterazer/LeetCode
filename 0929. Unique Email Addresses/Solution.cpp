#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> addresses;
        for (const string &email : emails) {
            string real;
            size_t i = 0;
            while (i < email.size() && email[i] != '+' && email[i] != '@') {
                if (email[i] != '.')
                    real.push_back(email[i]);
                i++;
            }
            while (email[i] != '@')
                i++;
            real += email.substr(i);
            addresses.insert(real);
        }
        return addresses.size();
    }
};
