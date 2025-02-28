#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)
    {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            food_map[foods[i]] = { ratings[i], cuisines[i] };
            cuisine_map[cuisines[i]].emplace(-ratings[i], foods[i]);
        }
    }

    void changeRating(string food, int newRating)
    {
        pair<int, string>& p = food_map[food];
        cuisine_map[p.second].erase({ -p.first, food });
        food_map[food] = { newRating, p.second };
        cuisine_map[p.second].emplace(-newRating, food);
    }

    string highestRated(string cuisine)
    {
        return cuisine_map[cuisine].begin()->second;
    }

private:
    unordered_map<string, pair<int, string>> food_map;
    unordered_map<string, set<pair<int, string>>> cuisine_map;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
