#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class NumberContainers {
public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        if (!data.contains(index)) {
            data[index] = number;
            num2idx[number].emplace(index);
        } else if (number != data[index]) {
            int old_val = data[index];
            num2idx[old_val].erase(index);
            if (num2idx[old_val].empty())
                num2idx.erase(old_val);
            data[index] = number;
            num2idx[number].emplace(index);
        }
    }

    int find(int number)
    {
        if (!num2idx.contains(number))
            return -1;
        return *num2idx[number].begin();
    }

private:
    unordered_map<int, int> data;
    unordered_map<int, set<int>> num2idx;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
