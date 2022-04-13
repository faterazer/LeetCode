#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (table.count(val))
            return false;
        else {
            data.emplace_back(val);
            table[val] = data.size() - 1;
            return true;
        }
    }

    bool remove(int val)
    {
        if (table.count(val)) {
            int idx = table[val];
            table[data.back()] = idx;
            swap(data[idx], data.back());
            table.erase(val);
            data.pop_back();
            return true;
        } else
            return false;
    }

    int getRandom()
    {
        uniform_int_distribution<int> dist(0, data.size() - 1);
        return data[dist(random_engine)];
    }

private:
    vector<int> data;
    unordered_map<int, int> table;

    default_random_engine random_engine;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
