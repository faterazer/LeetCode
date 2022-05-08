#include <vector>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger>& getList() const;
};

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger>& nestedList) : data(nestedList), idx(0), p(nullptr)
    {
    }

    ~NestedIterator() {
        delete p;
        p = nullptr;
    }

    int next()
    {
        if (p) {
            if (p->hasNext())
                return p->next();
            else {
                delete p;
                p = nullptr;
            }
        }
        if (data[idx].isInteger())
            return data[idx++].getInteger();
        p = new NestedIterator(data[idx++].getList());
        return next();
    }

    bool hasNext()
    {
        if (p) {
            if (p->hasNext())
                return true;
            else {
                delete p;
                p = nullptr;
            }
        }
        if (idx == data.size())
            return false;
        if (data[idx].isInteger())
            return true;
        p = new NestedIterator(data[idx++].getList());
        return hasNext();
    }

private:
    vector<NestedInteger> data;
    int idx;
    NestedIterator *p;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
