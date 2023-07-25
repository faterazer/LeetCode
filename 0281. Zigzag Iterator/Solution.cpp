#include <queue>
#include <vector>
using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if (!v1.empty())
            Q.emplace(make_pair(v1.begin(), v1.end()));
        if (!v2.empty())
            Q.emplace(make_pair(v2.begin(), v2.end()));
    }

    int next()
    {
        auto it = Q.front();
        Q.pop();
        int res = *it.first;
        if (it.first + 1 != it.second)
            Q.emplace(make_pair(it.first + 1, it.second));
        return res;
    }

    bool hasNext()
    {
        return !Q.empty();
    }

private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
