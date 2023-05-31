#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        memo[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        pair<string, int>& p = memo[id];
        string key = p.first + " " + stationName;
        timer[key].first += t - p.second;
        timer[key].second++;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string key = startStation + " " + endStation;
        return (double)timer[key].first / timer[key].second;
    }

private:
    unordered_map<int, pair<string, int>> memo;
    unordered_map<string, pair<int, int>> timer;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
