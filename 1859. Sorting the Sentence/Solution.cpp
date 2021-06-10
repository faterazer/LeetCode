#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string sortSentence(string s)
	{
		vector<string> vs(9);
		istringstream in(s);
		string res, word;
		while (in >> word)
			vs[word.back() - '1'] = word.substr(0, word.size() - 1);
		res = vs[0];
		for (size_t i = 1; i < vs.size() && vs[i].size(); i++)
			res += " " + vs[i];
		return res;
	}
};
