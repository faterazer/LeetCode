#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string reformatDate(string date)
    {
        unordered_map<string, string> m2n{
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
            {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
            {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
            {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        istringstream in(date);
        string year, month, day;
        in >> day >> month >> year;
        return year + "-" + m2n[month] + "-" + (day.size() == 4 ? day.substr(0, 2) : ("0" + day.substr(0, 1)));
    }
};
