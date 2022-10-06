#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class TimeMap {
public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = mp[key].upper_bound(timestamp);
        if (it == mp[key].begin())
            return "";
        return prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
