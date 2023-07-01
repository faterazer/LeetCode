#include <vector>
using namespace std;

class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec)
        : it(vec.begin())
        , end_it(vec.end())
    {
    }

    int next()
    {
        if (i == (*it).size()) {
            it++;
            i = 0;
        }
        return (*it)[i++];
    }

    bool hasNext()
    {
        while (it != end_it && i == (*it).size()) {
            it++;
            i = 0;
        }
        return it != end_it;
    }

private:
    vector<vector<int>>::iterator it, end_it;
    size_t i = 0;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
