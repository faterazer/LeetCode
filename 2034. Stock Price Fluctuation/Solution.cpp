#include <map>
#include <set>
using namespace std;

class StockPrice {
public:
    StockPrice()
    {
    }

    void update(int timestamp, int price)
    {
        auto it = records.find(timestamp);
        if (it != records.end())
            prices.erase(prices.find(it->second));
        records[timestamp] = price;
        prices.emplace(price);
    }

    int current()
    {
        return records.rbegin()->second;
    }

    int maximum()
    {
        return *prices.rbegin();
    }

    int minimum()
    {
        return *prices.begin();
    }

private:
    map<int, int> records;
    multiset<int> prices;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
