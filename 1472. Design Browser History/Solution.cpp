#include <string>
#include <vector>
using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage)
        : history({ homepage })
        , len(1)
        , idx(0)
    {
    }

    void visit(string url)
    {
        int n = history.size();
        if (n == idx + 1) {
            history.emplace_back(url);
            idx++;
        } else
            history[++idx] = url;
        len = idx + 1;
    }

    string back(int steps)
    {
        if (idx - steps >= 0)
            idx -= steps;
        else
            idx = 0;
        return history[idx];
    }

    string forward(int steps)
    {
        if (idx + steps < len)
            idx += steps;
        else
            idx = len - 1;
        return history[idx];
    }

private:
    vector<string> history;
    int len, idx;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
