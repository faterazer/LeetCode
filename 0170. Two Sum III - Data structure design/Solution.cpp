#include <unordered_map>
using namespace std;

class TwoSum
{
public:
    TwoSum()
    {
    }

    void add(int number)
    {
        cnt[number]++;
    }

    bool find(int value)
    {
        for (const auto &[k, v] : cnt)
        {
            long long complement = value - k;
            if (k == complement)
            {
                if (v > 1)
                    return true;
            }
            else
            {
                if (cnt.count(complement))
                    return true;
            }
        }
        return false;
    }

private:
    unordered_map<long long, int> cnt;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
