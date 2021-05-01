#include <string>
#include <vector>
using namespace std;

class OrderedStream
{
public:
    OrderedStream(int n) : vs(n), size(n)
    {
    }

    vector<string> insert(int idKey, string value)
    {
        vector<string> res;
        vs[idKey - 1] = value;
        if (idKey - 1 == ptr)
            while (ptr < size && !vs[ptr].empty())
                res.emplace_back(vs[ptr++]);
        return res;
    }

private:
    vector<string> vs; 
    int ptr = 0, size;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
